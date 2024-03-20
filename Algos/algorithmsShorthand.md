#### sliding window

##### sliding window fixed Position

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
