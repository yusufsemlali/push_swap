#!/bin/zsh

generate_list () {
  # Generate all numbers between -5000 and 5000
  jot -r $1 -5000 10000 |
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
