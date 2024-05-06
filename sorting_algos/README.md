# Sorting Algorithms

## Algorithm Complexity

The time and space complexity of the bubble sort algorithm are as follows:

### Time Complexity:
- **Best Case:** O(n) - when the input array is already sorted. In this case, the algorithm will only need to make a single pass through the array to confirm that it's sorted, resulting in linear time complexity.
- **Average Case:** O(n^2) - In the average case, the algorithm makes n * (n-1) / 2 comparisons and swaps, where n is the number of elements in the array. This results in quadratic time complexity.
- **Worst Case:** O(n^2) - when the input array is in reverse order. In the worst case, the algorithm will make the maximum number of comparisons and swaps, resulting in quadratic time complexity.

### Space Complexity:
- Bubble sort is an in-place sorting algorithm, meaning it doesn't require any additional space other than the input array itself. Therefore, its space complexity is O(1), indicating constant space usage regardless of the size of the input array.

In summary, while bubble sort is easy to understand and implement, it's generally not efficient for large datasets due to its quadratic time complexity. It's primarily used for educational purposes or for sorting small datasets where simplicity is more important than efficiency.


## Running `dtrace` 

- install `dtrace` from brew `brew install flamegraph`
  
```
sudo dtrace -x ustackframes=100 -n 'profile-97 /pid == $target/ { @[ustack()] = count(); } tick-60s { exit(0); }' -c "./your_executable" -o out.stacks -P
stackcollapse.pl out.stacks > out.folded
flamegraph.pl out.folded > flamegraph.svg 
```