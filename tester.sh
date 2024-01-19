#!/bin/sh

# Function to generate a list of random numbers
# generate_list () {
#   i=1
#   while [ $i -le $1 ]
#   do
#     # Use the current nanoseconds to generate a pseudo-random number between -10 and 10
#     echo $(( $(date +%N) % 21 - 10 ))
#     i=$((i+1))
#   done | tr '\n' ' ' # This will replace newlines with spaces
# }
# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
NC='\033[0m' # No Color


generate_list () {
  # Generate all numbers between -10 and 10
  seq 0 10000 | 
  # Shuffle the numbers
  shuf |
  # Take the first $1 numbers
  head -n $1 |
  # Replace newlines with spaces
  tr '\n' ' '
}

# Check if a number was provided
if [ -z "$1" ]
then
  echo "Please provide the number of elements."
  exit 1
fi

# Generate the list
list=$(generate_list $1)

echo "List: $list"
echo "Number of elements: $1"

# Run push_swap and measure its time
/usr/bin/time -o time.txt -f "%e" ./push_swap $list > push_swap_output.txt

push_swap_output=$(cat push_swap_output.txt)

echo "Number of Actions: $(echo "$push_swap_output" | wc -l)"

# Run checker_linux
checker_output=$(echo "$push_swap_output" | ./checker_linux $list )

# Get the real time from the output
real_time=$(cat time.txt)

# echo how long it took to run 
echo "Time it took to run: $real_time seconds"
# ...

# Colorize the output
printf "Checker Output: "
if [ "$checker_output" = "OK" ]
then
  printf "${GREEN}%s${NC}\n" "$checker_output"
elif [ "$checker_output" = "KO" ]
then
  printf "${RED}%s${NC}\n" "$checker_output"
elif [ "$checker_output" = "Error" ]
then
  printf "${ORANGE}%s${NC}\n" "$checker_output"
else
  printf "%s\n" "$checker_output"
fi