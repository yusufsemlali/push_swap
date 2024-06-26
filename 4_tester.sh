#!/bin/bash

# Define the set of numbers
numbers="1 2 3 4"

# Use a permutation function or a tool like 'perm' to generate all permutations
# For simplicity, this example manually lists permutations, but in practice, you should generate them programmatically
# This is a placeholder for the actual permutation generation logic
permutations=(
  "1 2 3 4"
  "1 2 4 3"
  "1 3 2 4"
  # Add all other permutations here
)

# Loop through each permutation
for perm in "${permutations[@]}"; do
  # Run push_swap and capture its output
  operations=$(./push_swap "$perm")
  
  # Use the output of push_swap as input to checker_linux along with the original permutation
  result=$(echo "$operations" | ./checker_linux "$perm")
  
  # Check if the result is OK
  if [ "$result" == "OK" ]; then
    echo "Permutation $perm: Correctly sorted"
  else
    echo "Permutation $perm: Sorting failed"
  fi
done
