## Sliding Window:

**The Sliding Window Technique** is a problem-solving technique that is used to
**1.Running Average:** Use a sliding window to efficiently calculate the average of a fixed-size window as new elements arrive in a stream of data.

**2.Formulating Adjacent Pairs:** Sliding windows are useful when you need to process adjacent pairs of elements in an ordered data structure, allowing you to easily access and operate on neighboring elements.

**3.Target Value Identification:** When you want to find a specific target value or combination of values in an array,

**4.Longest/Shortest/Most Optimal Sequence:** Sliding windows are handy when you need to find the longest, shortest, or most optimal sequence that satisfies a given condition in a collection.
The main idea behind the sliding window technique is to convert **two nested loops into a single loop**. Usually, the technique helps us to reduce the time complexity from **O(n²) or O(n³) to O(n)**.

**Both fixed and variable window sliding window problems** can use the techniques of **hashing, two pointers, and sliding window optimization.**

**a.Hashing** is a common technique for tracking the elements in a sliding window. This is because a hash table can quickly and efficiently look up the presence of an element in the window.  
**b.Two pointers is another common technique** for tracking the elements in a sliding window. This is because two pointers can easily track the start and end of the window.  
**c.Sliding window optimization** is a technique that combines hashing and two pointers to improve the performance of the sliding window algorithm. This is done by using hashing to quickly look up the presence of an element in the window, and using two pointers to track the start and end of the window.  
**The choice of technique for solving a sliding window problem depends on the specific problem and the constraints of the problem.** For example, if the sliding window is small, then hashing may be a good choice. However, if the sliding window is large, then two pointers may be a better choice.

**Lets discuss How to identify Fixed and variable size Window**

**1.Fixed Window:**

In a fixed window problem, **we have a predefined window size that remains constant** throughout the problem-solving process.  
The template for solving a fixed window problem involves maintaining two pointers, **low and high, that represent the indices of the current window.**  
The process involves iterating over the array or sequence, adjusting the window as necessary, and performing computations or operations on the elements within the window.  
Here's the template

```
fixed_window()
{
    int low = 0, high = 0, windowsize = k;
    while (i < sizeofarray)
    {
        // Step 1: Create a window that is one element smaller than the desired window size
        if (high - low + 1 < windowsize)
        {
            // Generate the window by increasing the high index
            high++;
        }
        // Step 2: Process the window
        else
        {
            // Window size is now equal to the desired window size
            // Step 2a: Calculate the answer based on the elements in the window
            // Step 2b: Remove the oldest element (at low index) from the window for the next window

            // Proceed to the next window by incrementing the low and high indices
        }
    }
}
```

# Example on above Format

**Q->Given an array arr\[\] and an integer K, the task is to calculate the sum of  
all subarrays of size K.**

```
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    // Input array
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = 0; // Window indices
    int sum = 0; // Current window sum

    while (j < n)
    {
        if (j - i + 1 < k)
        {
            // Expand the window by adding element at index j to the sum
            sum += v[j];
            j++;
        }
        else
        {
            // Window size is now equal to the desired window size
            // Calculate the answer for the window
            sum += v[j];
            cout << sum << endl;

            // Move the window by incrementing indices i and j
            sum -= v[i];
            i++, j++;
        }
    }
}
```

**2 variable window**

In a variable window problem,**the window size is not fixed and can change dynamically based on certain conditions or criteria**. The template for solving a variable window problem involves maintaining two pointers, start and end, which represent the indices of the current window.

Initialize the window indices: Start by initializing the start and end pointers to the first element of the sequence or array.

**Expand the window:** Check a condition to determine whether to expand the window. If the condition is satisfied, increment the end pointer to expand the window size.

**Process the window:** Once the window size meets the desired criteria or condition, perform the required computations or operations on the elements within the window.

**Adjust the window size:** If the window size exceeds the desired criteria, adjust the window by moving the start pointer. Iterate or loop until the window size matches the desired criteria, and update the window accordingly.

```
variable_window()
{
    int start = 0, end = 0;
    while (end < n)
    {
        // Perform calculations or operations within the window

        /* Case 1: Expand the window
           If the window size is less than the desired value (k), increase the end index
        */
        if (end - start + 1 < k)
        {
            end++;
        }

        /* Case 2: Window of desired size
           If the window size is equal to the desired value (k), process the window and calculate the answer
        */
        else if (end - start + 1 == k)
        {
            // Perform the required calculations or operations to obtain the answer
            // Store the answer in a variable (ans)

            end++;
        }

        /* Case 3: Reduce the window size
           If the window size is greater than the desired value (k), adjust the window by moving the start index
        */
        else if (end - start + 1 > k)
        {
            while (end - start + 1 > k)
            {
                // Remove calculations or operations involving the element at the start index

                start++;
            }

            // Check if the window size becomes equal to the desired value (k) after adjustment
            if (end - start + 1 == k)
            {
                // Perform calculations or operations and store the answer if necessary
            }

            end++;
        }
    }

    // Return the final answer (ans)
}
```

# Eg on Above format

**1\. [longest-substring-without-repeating-characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)**

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        map<char, int> m; // Map to track characters in the current window

        while (j < s.size()) {
            m[s[j]]++; // Add current character to the map
            int windowSize = j - i + 1; // Calculate the current window size

            if (m.size() == windowSize) {
                ans = max(ans, windowSize); // Update the maximum length of the substring
                j++; // Expand the window by moving the end pointer
            }
            else {
                while (m.size() < windowSize) {
                    m[s[i]]--; // Remove characters from the start of the window
                    if (m[s[i]] == 0)
                        m.erase(s[i]);
                    i++; // Move the start pointer to adjust the window
                    windowSize = j - i + 1; // Update the window size
                }

                if (m.size() == windowSize) {
                    ans = max(ans, windowSize); // Update the maximum length of the substring
                }

                j++; // Expand the window by moving the end pointer
            }
        }

        return ans; // Return the length of the longest substring
    }
};

```

**Questions On Fixed window size**

1. [Substrings-of-size-three-with-distinct-characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)
2. [Substring-with-concatenation-of-all-words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)
3. [Maximum-number-of-vowels-in-a-substring-of-given-length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)
4. [Maximum-number-of-occurrences-of-a-substrin](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)
5. [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/description/)
6. [Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)
7. [Find-all-anagrams-in-a-string](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)
8. [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/description/)
9. [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/solutions/1772628/Java-or-Sliding-Window-template-or-Explained/)

**Questions On variable window size**

1. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
2. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)
3. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)
4. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)
5. [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)
6. [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/)
7. [Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/description/)
8. [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/description/)
9. [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)
10. [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/description/)
11. [Subarrays-with-k-different-integers](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

**If you want to master Two pointer Must do these patterns**

# 1\. Running from both ends of an array

```
a. 2 Sum problem
b. Trapping Water
c. Next Permutation
d. Reversing / Swapping
f. Others
```

# 2\. Slow & Fast Pointers

```
a.Linked List Operations
b.Cyclic Detection
c.Sliding Window/Caterpillar Method
d.Rotation
e.Remove Duplicate
```

# 3\. Running from beginning of 2 arrays / Merging 2 arrays

```
a. Sorted arrays
b. Intersections/LCA like
c. Meet-in-the-middle / Binary Search
d. Median Finder
e. SubString
```

# 4\. Split & Merge of an array / Divide & Conquer

```
  a. Partition
  b. Sorting
```

These are standard Two pointer pattern discussed above :-> You can follow his article  
**[All-Type of-two-pointers-problems-Link](https://leetcode.com/discuss/study-guide/1688903/Solved-all-two-pointers-problems-in-100-days)**

**If you stuck in bits I must say follow this**  
**[All-types-of-patterns-for-bits-manipulations-and-how-to-use-it](https://leetcode.com/discuss/interview-question/3695233/all-types-of-patterns-for-bits-manipulations-and-how-to-use-it)**

# I'd love to hear your thoughts feel free to leave comments or questions .
