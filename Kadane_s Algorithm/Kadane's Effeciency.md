# Kadane’s Algorithm

**Kadane's Algorithm** is a popular **Dynamic Programming** technique used to solve the **Maximum Subarray Sum** problem efficiently.

Given an array of integers (positive, negative, or zero), the goal is to find the **contiguous subarray** with the **largest sum** and return that sum.

---

## Algorithm Mechanism

1. Initialize:
   - `sum = 0`
   - `maxSum = arr[0]` (first element of the array)

2. Iterate through the array (from index 0 to n-1):
   - `sum += arr[index]`
   - `maxSum = max(sum, maxSum)`
   - If `sum < 0`, reset `sum = 0`

3. Return `maxSum`

---

## Simulation Example

**Input Array:** `[-9, -8, -7, -4, -5, -1]`

| Index | Element | `sum`          | `maxSum` | Action                  |
|-------|---------|----------------|----------|-------------------------|
| 0     | -9      | -9             | -9       | Reset `sum = 0`         |
| 1     | -8      | -8             | -8       | Reset `sum = 0`         |
| 2     | -7      | -7             | -7       | Reset `sum = 0`         |
| 3     | -4      | -4             | -4       | Reset `sum = 0`         |
| 4     | -5      | -5             | -4       | Reset `sum = 0`         |
| 5     | -1      | -1             | -1       | Reset `sum = 0`         |

**Output:** `-1` (Correct, since all numbers are negative)

---

## Why is Kadane’s Algorithm Efficient?

There are three main approaches to solve the Maximum Subarray Sum problem:

| Approach              | Time Complexity | Performance     |
|-----------------------|-----------------|-----------------|
| Brute Force (Naïve)   | **O(n²)**       | Slowest         |
| Divide and Conquer    | **O(n log n)**  | Moderate        |
| **Kadane’s Algorithm**| **O(n)**        | **Fastest**     |

Kadane’s Algorithm is the most optimal solution with **linear time complexity**.

