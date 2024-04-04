## Slow Pointer Fast Pointer

## Binary Search

## Floyed Wessel's Cycle Detection

## Cycle Sort

## 2 pointer

## Kadane Algo : get maximum subarray sub of an array

```cpp
// kadane algorithm
// two vairable currSum, globalSum
/*
** for each num in nums
**      currSum += num;
**      if (currSum > globalSum ) globalSum = currSum;
**      if (currSum < 0 ) currSum = 0;
**
** return globalSum;
*/
```

[leetcode 53](https://leetcode.com/problems/maximum-subarray/description/)

### Sliding Window : get the maximum sized array of given condition

#### Atmost : count number of subarray of a given condition

## Dynamic Programming (DP)

#### for loop existed DP

### Top Down or Recursive

### Bottom UP or Iterative

## Interval Problems

## Tree Traversal

### BFS

### DFS

#### PreOrder, InOrder, PostOrder

## Bit Manipulation

### Swaping using Bit Manipulation

```cpp

void swap (int& a, int& b){
    a = a^b;
    b = a^b;
    a = a^b;
    return;
}
```
