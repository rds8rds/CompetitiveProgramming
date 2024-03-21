#### sliding window

##### sliding window fixed sized

```cpp
fixed_window()
{
    int low = 0, high = 0, windowsize = k;
    while (high < sizeofarray)
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

            // Proceed to the next window by incrementing the low and high indices [low++ high++]
        }
    }
}
```

**Q->Given an array arr\[\] and an integer K, the task is to calculate the sum of  
all subarrays of size K.**

```cpp

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int hi = 0, lo = 0, sum = 0;
        int res = 0;

        while( hi < arr.size() ){
            if( hi - lo + 1 < k){
                sum += arr[hi];
                hi++;
            }else{
                sum += arr[hi];
                res += sum/k >= threshold ? 1:0;

                sum -= arr[lo];
                lo++;
                hi++;
            }
        }
        return res;
    }
};
```

##### sliding window variable sized

```cpp

//always follow templater

while( ri  <  string.size()){

    // any updatef computation to help the if condition

    if( some condition to check ){
        increase ri ptr;
    } else{
        while( as long as true ){
            increase le ptr;
        }
    }
}

```

**Eg on Above format**

**[76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)**

```cpp
class Solution {
public:

    bool is_mT_present_in_mS(unordered_map<char, int>& mS, unordered_map<char, int>& mT){
        for(auto it : mT){
            char target = it.first;
            if(mS.find(target) == mS.end() )return false;
            if(mS[target] < mT[target] ) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int>mS, mT;
        pair<int, int> res({ 0, 1e9 }); //{le , ri }

        for(auto ch : t){
            mT[ch]++;
        }

        int le = 0, ri = 0;
        while( ri < s.size() ){
            mS[s[ri]]++;

            if(!is_mT_present_in_mS(mS, mT)){
                ri++;
            }else{
                while(is_mT_present_in_mS(mS, mT)){
                    if(ri - le + 1 < res.second - res.first + 1) res = {le, ri};

                    // dealing with le
                    mS[s[le]]--;
                    if( mS[ s[le] ] == 0) {
                        mS.erase(s[le]);
                    }
                    le++;
                }
                ri++;
            }
        }

        string ret = s.substr( res.first , res.second - res.first + 1);
        return  res.second == 1e9 ? "": ret ;
    }
};

```

**1. [longest-substring-without-repeating-characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)**

```cpp

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
