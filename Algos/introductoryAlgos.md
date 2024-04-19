## Slow Pointer Fast Pointer

## Binary Search

## Floyed Wessel's Cycle Detection

## Cycle Sort

## 2 pointer

### Dutch National Flag Algorithm ( 3 pointers algo)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while( mid <= high ){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++, mid++;
            } else if ( nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// all 0's are to set before low
// all 2's are set after high ptr
// 1's are set in between low to mid
// when mid crosses high we say our sorting is done
```

[leetcode 75](https://leetcode.com/problems/sort-colors/description/)

## Kadane Algo : get maximum subarray sum of an array

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
