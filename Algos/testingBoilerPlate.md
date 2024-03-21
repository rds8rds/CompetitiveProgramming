#### For DS

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){

    array<int, 26>arr; // an upgradedd array off 26 size
    vector<int> vec;
    pair<int, int> p;
    unordered_map<char, int> mp;
    map<char, int> mpOrdered;// random access costs O(long(n)) here n = size of map; [red-black tree ]
    unordered_set<int> collection; // instant access time O(1);
    set<int> gathering; //O(log(n)) access time
    priority_queue<int> maxHeap; // max is in the top
    priority_queue<pair<int, int>> maxHeapOfPair // sometimes we need pair like this
    priority_queue<int, max<int>> minHeap; // for minheap we need max comparator funcition object

    queue<int> que;
    stack<int> stack;


    // functions available for each DS
    // for array we got size(), fill(), sort(), max_element(), min_element() , accumulate(), range_based for loop

    // for vector we got insert(), push_back(), pop_back(), clear(), resize(), sort(), max_element(), find(), accumulate;

    // for pair most common are pair.first and pair.second member functions [ also swap() ]

    // for unordered_map: insert(), mp.at() or mp[], size(), clear(), Find();

    // for map (ordered map): isert(), mpOrdered.at(), or mpOrdered[], find(), size(), clear(), find();

    // for set:


}
```
