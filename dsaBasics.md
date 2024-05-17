#### For DS

##### string

###### substr(), stoi(), stoll()

```cpp

    string a = "abc", b;
    b = a.substr(0, 2); // b = ab;
    a = "123";
    int x = stoi(a);
    long long y = stoll(a);

    // stoi() and stoll() will throw exception if input is non-numeric
    a ="";
    x = stoi(a); // stoi throws bad input exception

```

```cpp

// sentence to word converter
vector<string> wordConverter(string s){
    int i = 0;
    vector<string> res;
    while( i < s.size()){
        while( i < s.size() and s[i] == ' ') i++;
        int j = 0;
        while( i + j < s.size() and s[i + j] != ' '){
            j++;
        }
        // j is size of substring after i;
        res.push_back(s.substr(i, j));
        // update i
        i = i + j;
    }
    return res;
}

// using with stl

#include <iostream>
#include <sstream>
using namespace std;


int main()
{
    string s = "Lia has a blue coat";
    stringstream ss(s);
    // ss << s;  also accepted;
    string temp;

    string content = ss.str(); // converting stringstream to string

    while (ss >> temp) cout<<temp<<"-"; // sending one word at a time to temp;
    return 0;
}


```

##### vector

###### initialization and copying

```cpp
int main(){
    vector<int> vec;
     // for vector we got insert(), push_back(), pop_back(), clear(), resize(), sort(), max_element(), find(), accumulate;
     // clear() deletes all items of vector and sets its size to zero;
     // for reusing same vector in different cases
     // flow: vector initialize -> vec clear() -> vec resize()

    // vector initializing technique;

    // 1. using braced initializer ( a variety of uniform initialization syntax )
    vector<int> a{1,2,4};

    // 2. using special size and default value
    vector<int> b(5,0);

    // 3. using iterator to initalize from another container
    vector<int> copy_b(b.begin(), b.end());

    // 4. using uniform initialization syntax
    vector<int> c = {1,3,5,6,7};

    // vector copy in a range

    vector<int> original{1,2,3,5,6,6,8}, copy;
    copy = vector<int> (original.begin(), original.end()); // coppying entire vector
    auto copy_two = vector <int>(original.begin() + 1, original.begin() + 5); //copying from 1 index to untill 5 [which is 1..4]
    /*
    ** vector<int>(copy_start_iterator, copy_end_iterator) copy will end when it hits copy_end_iterator
    **
    ** also string tmp = string(copy_start_iterator, copy_end_iterator) will work
    ** it is very similar with str.substr(copy_start_index, copy_size) function of string
    ** where substr() will generate substring of a string from copy_start_index to a certain sized string;
    **
    */
}

```

###### vector find(), erase()

```cpp
int main(){
    vector vec{1,2,4,4,6};

    // finding first occurance of 4;
    vector<int>::iterator it = find(vec.begin(), vec.end(), 4); // or just auto it =

    // earasing vector.erase( iterator it);

    vec.erase(it);
    // now vec = {1, 2, 4, 6};
}
```

#### Structure

Structure acts as an template for creating variable, it is much like type with more functionality!

Defination:

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :  val(x), next(NULL) {} // struct constructor
};
```

#### Miscellaneous

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){

    array<int, 26>arr; // an upgradedd array off 26 size
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



    // for pair most common are pair.first and pair.second member functions [ also swap() ]

    // for stack : push() but not clear() function available

    // for unordered_map: insert(), mp.at() or mp[], size(), clear(), Find();

    // for map (ordered map): isert(), mpOrdered.at(), or mpOrdered[], find(), size(), clear(), find();

    // for set:

    // for priority_queue we got push(), top(), pop()

    // memset : memset(mem,-1, sizeof(mem));



}
```
