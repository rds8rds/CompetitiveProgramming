## পারমুটেশন ও কম্বিনেশন

পারমুটেশন কম্বিনেশন এর কন্সেপ্ট মনে আছে তো, ফর পারমুটেশন আমাদের দরকার
সকল ধরনের প্যাটার্ন যেগুলোকে আমরা তাদের পাশাপাশি অবস্থানের আলোকে আলাদা করতে পারি;

lets say nums = {1,2,3};

1, 2, 3 and 1, 3, 2 both are different permutaiotns of nums although
1,2,3 and 1,3,2 basically have same numbers in each pattern; here digits having different neighbours makes difference;

কিন্তু কম্বিনেশনে কিন্তু এসব আলাদা আলাদ নয়; ১, ২, ৩ কিংবা ১, ৩, ২ আসলে একই কম্বিনেশন কিন্তু পারমুটেশনের খেত্রে এরা আলাদা

nums = {1, 2, 3} এর জন্য পারমুটেশন হবে ( numsP3 ) {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}; এই মোট ৬ টি;
আর ৩ সাইজের কম্বিনেশন হবে {1,2,3}

আমরা খুব সহজেই DP ব্যবহার করে এদের জন্য কোড করতে পারি, এক্ষেত্রে আমরা একটা এক্সট্রা ভেক্টর রাখব, যেটার কাজ থাকবে আমরা কি কি নাম্বার ব্যবহার করে ফেলেসি অলরেডি সেটার ট্রাক রাখা

```cpp
void permutation(vector<int>& nums, vector<bool>& placeHolder, vector<int>& res ){

    if(res.size() == nums.size()){
        print(res); // a print function to print vector;
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(placeHolder[i] != true ){ // if not used then include
            placeHolder[i] = true;
            res.push_back(nums[i]);
            permutation(nums, placeHolder, res);
            // ব্যাকট্রাক
            res.pop_back();
            placeHolder[i] = false;
        }
    }
    return;
}
```

কম্বিনেশনের জন্যও ঠিক এভাবে একটা কোড লিখে ফেলা যায়; যেমন

```cpp
void combination(vector<int>& nums, vector<bool>& placeHolder, vector<int>& res, int k ){
    if( k == 0 ) print(res);

    for(int i = 0; i< nums.size(); i++){
        if(placeHolder[i] != true ){
            placeHolder[i] = true;
            res.push_back(nums[i]);
            combination(nums, placeHolder, res, k-1);
            // ব্যাকট্রাক
            res.pop_back();
            placeHolder[i] = false;
        }
    }
}
```

তবে পারমুটেশন বের করার কিন্তু আরো কিছু টেকনিক আছে, যেমন নিচের কোডটি তে আমারা শুধু পাশাপাশি নাম্বার সোয়াপ করেই পারমুটেশন বের করতে পারি; এখানেও আমরা রিকারশন ব্যাবহার করেছি

```cpp
void generatePermutations(vector<int>& nums, int start) {
    if (start == nums.size()) {
        // Print the current permutation
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1);
        swap(nums[start], nums[i]); // Backtrack
    }
}
```

মেইন ফাংশন টাও এখানে দেখানো হল

```cpp
int main(){

    vector<int> nums{1,2,4};
    vector<bool> places(nums.size(), false);
    vector<int> res;
    permutation(nums, places, res);
    combination(nums, places, res, 2);

    generatePermutations (nums, 0);
}

```

## n Queens প্রব্লেম

আইডিয়া টা হল আমারা চেক বোর্ডে (৮\*৮) আমারা n টা মন্ত্রীকে কিভাবে ফিট করা যাবে ? প্রব্লেমটা ডিপি দিয়ে চিন্তা করা খুব সহজ; তবে তার আগে আমাদের জানতে হবে দাবার বোর্ডে মন্ত্রীর ঘরগুলোকে কিভাবে মার্ক করা যায় ?

এর পর দাবার row গুলোকে পর্যায় ক্রমে access করব; এবং এক একটি row তে এক একটি করে মন্ত্রী বসাবো; কিন্তু কোন কলামে বসবে এটা নির্ভর করবে নতুন মন্ত্রী যেন কোন ভাবেই পুর্বের কোন মন্ত্রীরকে চেক দিয়ে না ফেলে! এখন প্রশ্ন হল কিভাবে আমরা মন্ত্রীর ইনফুলেনশিয়াল ঘর গুলোকে মার্ক করতে পারি ? একটা মন্ত্রীর ইনফুলেন্স থাকে তার row এবং column, আর তার থেকে কোনাকুনি ঘর গুলোতে;
দাবা বোর্ডের যেকোন কোনা কুনি ঘর গুলো দুটি সূত্র মেনে চলে;

১। ঘর গুলো নিচের বাম থেকে উপরে ডানে উঠলে `row + colmn` কোনাকুনি লাইন টার জন্য নির্দিষ্ট থাকে
২। ঘর গুলো নিচের ডান থেকে বামে উপরে উঠলে `row - colmn` কোনাকুনি লাইন টার জন্য নির্দিষ্ট থাকে

> diagonal_axis_1 = row + column = constant
> diagonal_axis_2 = row - column = constant
> we use n + row - column for always postitive value

তাইলে আমরা এই দুটি সূত্র দিয়ে প্রত্যেক মন্ত্রী এর জন্য আমরা তার দুটি কর্ণকে হিসাবের মধ্যে রাখতে পারব

```cpp

#include<bits/stdc++.h>

using namespace std;

// column number of queen at ith row = queen[i];
int queen[20];

// arrays to mark if there is queen or not
int column[20], diagonal1[40], diagonal2[40];
int cnt = 0;

void nqueen(int at, int n){
    if(at == n+1){
        cnt++;
        cout<<"count: "<<cnt<<endl;
        for( int i = 1; i <= n; i++){
            cout<< "row col = "<<i <<" "<< queen[i]<<endl;
        }
        cout<<endl;
        return;
    }

    for(int i = 1; i <= n; i++){ // আমারা ফর লুপে কলাম কে choose করছি
        // column[i]             --> i তম কলামে কোন কুইন আছে কিনা ?
        // diagonal1[i + at]     --> প্রথম কলামের সূত্র
        // diagonal2[n + i - at] --> দিত্বীয় কলামের সূত্র ( এখনে n যোগ করা আছে, যেন -ve না হতে পারে)
        if ( column[i] or diagonal1[i + at] or diagonal2[n + i - at]) continue; // হিসাব করার দরকার নেই কারন অলরেডি অন্য কুইন এর ইনফুলেন্সে রয়েছে জায়গাটা [at, i];

        queen[at] = i;
        column [i] = 1, diagonal1[i + at] = 1, diagonal2[n + i - at ] = 1;
        //cout<<"success";
        // calling the next qeen to place on the board
        nqueen(at + 1, n);
        //cout<<"backtracking"<<endl;
        column [i] = 0, diagonal1[i + at] = 0, diagonal2[n + i - at ] = 0;
    }
}

int main(){
    nqueen(1, 8);
}
```

আর হ্যাঁ, ৮\*৮ বোর্ডে ৮ টা কুইনের জন্য টোটাল ৯২ টা সমাধান আছে;
এই প্রোব্লেম এর আরো অপটিমাইজেশন করা সম্ভব ফলে টোটাল প্রব্লেম এর রানটাইম পুরা অর্ধেক করে নেওয়া যাবে।

## স্ট্যাক

স্ট্যাক এর খুব জনপ্রিয় ৪ টা সমস্যা হলঃ

১। ডানের সবথেকে কাছের ছোট নাম্বার বা পরবর্তি ছোট নাম্বার ( nearest smaller right ) <br>
২। বামের সবথেকে কাছের ছোট নাম্বার বা পূর্ববর্তি ছোট নাম্বার ( nearest smaller left )<br>
৩। ডানের সবচেয়ে কাছের বড় নাম্বার বা পরবর্তি বড় নাম্বার ( nearest larger right )<br>
৪। বামের সবচেয়ে কাছের বড় নাম্বার বা পূর্ববর্তি বড় নাম্বার ( nearest larger left )<br>

ধরা যাক আমার কাছের একটা ভেক্টর **A = { 2, 1, 5, 6, 2, 3}** <br>

এর জন্য যদি আমরা ডানের সবচেয়ে কাছের ছোট নাম্বার এর ভেক্টর তৈরি করি; সেটা হবে nearestSmallerRight(A) = {1, -1, 2, 2, -1, -1};
এখানে -1 বলতে বুঝাচ্ছি যে সেই সংখ্যার ডানে সেই সংখ্যার চেয়ে কোনো ছোট সংখ্যা নেই; যেমন 2 এর জন্য আমারা এর ডানে সবচেয়ে কাছে পাই 1 কে, 1 এর জন্য কিন্তু কেউ নেই তাই সেখানে -1, এর পর 5 এর জন্য আমরা পাই 2 কে, 6 এর জন্য 2, 2 এর জন্য কেউ নেই -1, 3 এর জন্য কেউ নেই তাই -1;

কিন্তু আমারা যখন ডানের সবচেয়ে কাছের ছোট নাম্বার খুজি তখন সাধারনত আমারা ভ্যালু না খুজে আমারা খুজি ছোট নাম্বার টার ইন্ডেক্স, এতে অনেক গুলো লাভ আছে; <br>
যেমনঃ

> আমারা যে -1 কে, যে নাম্বার এর ছোট নাম্বার নাই সেখানে বসাচ্ছি; সেটা কাজ করবে না যখন মূল ভেক্টর এ -1 থাকবে
> আবার শুধু ভ্যালু দিয়ে আমারা কখনোই নির্দিষ্ট করে বলতে পারি না ঠিক কোন নাম্বর টা আমাদের পরবর্তি ছোট নাম্বার; (অনেক গুলো একই নাম্বার থাকতে পারে )

তো আমরা ইন্ডেক্স দিয়ে যদি সেইম ভেক্টর এর জন্য তৈরি করি সেটা হবেঃ **nearestSmallerRight(A) = {1, 6, 4, 4, 6, 6};** <br>
এখানে 6 ইন্ডেক্স আমারা সেই সকল নাম্বার এর জন্য ব্যাবহার করেছি, যাদের ডানে তাদের চেয়ে বড় কোন নাম্বার নেই;
যেহেতু 6 মূল আরে এর সর্বডানের ইনডেক্স হতে 1 বেশি সেই জন্যেই ব্যবহার করা; এর পর থেকে আমরা যখন ডানের পরবর্তি নাম্বার বলব তখন আমরা
নাম্বার বলতে ইনডেক্সই বুজব

কিন্তু আমরা কিভাবে সর্বডানের ছোট নাম্বার এর ইনডেক্স বের করব ?

একটা পসিবল উত্তর হল **মনোটনিক স্ট্যাক** ব্যাবহার করা;

### মনোটনিক স্ট্যাকঃ ক্রমিক বর্ধ্মান অথবা ক্রমিক হ্রাসমান এলিমেন্ট এর স্ট্যাক

যেহেতু আমরা দেখব আমাদের কোন নাম্বার এর ডানে কোন ছোট নাম্বার আছে কিনা; এবং আমরা আরে ট্রাভার্স করার সময় সেই নাম্বার এ থেকেই তার ডানে কোন নাম্বার ছোট থাকার তথ্য নিশ্চিত ভাবে জানতে চাই তাইলে আমাদের উচিত ডান থেকেই আরে ট্রাভার্স করা; এর ফলে আমরা আগে ট্রাভার্স করা নাম্বার দেখেই বলে দিতে পারব এর আগে current নাম্বার এর চেয়ে ছোট কোন নাম্বার এসেছিল কিনা?

আর এই লাস্টের লজিকটাই আমরা ইমপ্লিমেন্ট করতে পারি একটা মনোটনিক স্ট্যাক ( monotonically increasing stack ) দিয়ে; আমরা এমন স্ট্যাক বানাব যেখানে নতুন নাম্বার(current) স্ট্যাক এ খুজবে তার থেকে ছোট কোন নাম্বার স্ট্যাক এ আছে কিনা ? যদি থাকে তো সেই নাম্বার এর ইনডেক্সই ( স্ট্যাক টপ এ পাওয়া যাবে ) হবে current নাম্বার এর পরবর্তি ছোট নাম্বার এর ঠিকানা; আর এর পর অবশ্যই current নাম্বারকে (index) স্ট্যাক টপ এ বসিয়ে দিতে হবে, কারন এর পরবর্তি কোন নাম্বার এর জন্য হয়তবা এই নাম্বারটাই হতে পারে পরবর্তি ছোট নাম্বার;

আর যদি স্ট্যাক এর নিচ পর্যন্ত গিয়েও কিছু না খুজে পাই, সেই ক্ষেত্রে আমরা বলব কারেন্ট নাম্বার এর জন্য আমাদের স্ট্যাকে কোন ছোট নাম্বার নেই তাই আমরা current নাম্বার এর জন্য ভেক্টর এর শেষ ঠিকানার পরের ইনডেক্সকে (invalid index) দেখিয়ে দিব (another way of putting -1 for that number); এর পর পূর্বের মত করে স্ট্যাক এর মধ্যে নিজের ইন্ডেক্সকে বসিয়ে দিব;

> -1 না বসিয়ে n = vector size() বসানোর কারনটা প্রোব্লেম স্পেসিফিক; বাট ডানের দিকের ছোট নাম্বার বলে আমি এখানে সংখ্যা রেখার ডানের ইনডেক্স কে দেখিয়ে দিলাম;

```cpp

vector<int> nearestSmallerRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n); // Initialize result vector with n where no valid value is present
    stack<int> s; // stack to store indices of elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from stack while stack is not empty and
        // the top element is greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the nearest smaller element in right is stack top
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element's index onto the stack
        s.push(i);
    }

    return result;
}

```

আবার পূর্ববর্তি ছোট নাম্বার কে খুজতে হলে আমরা সেইম আপ্রোচ এই আগাব শুধু চেঞ্জ হবে যে ব্যাপারটা সেটা হল নাম্বার যেহেতু পূর্ববর্তি তাই সেটা ছোট বা বড় যাই হোক সেটা আসবে কারেন্ট নাম্বার এর পূর্বে; আর তাই আমাদেরকে আরে ট্রাভার্স করা লাগবে এবার বাম থেকে ডানে; আর
current নাম্বার এর থেকে ছোট নাম্বার না খুজে পেলে আমরা বলে দিব -1 ইন্ডেক্স এ আমাদের ছোট নাম্বারটা রয়েছে;

```cpp
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> s; // Stack to store indices of elements

    for (int i = 0; i < n; ++i) {
        // Pop elements from stack while stack is not empty and
        // the top element is greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the nearest smaller element in left is the top element of the stack
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element's index onto the stack
        s.push(i);
    }

    return result;
}

```

এবার আমারা দেখি কিভাবে ডানের সবচেয়ে কাছের বড় নাম্বারটা পেতে পারি, এজন্য আমরা ডান থেকে আবার স্ট্যাক এ নাম্বার পুশ করা শুরু করব, যদি দেখি আগে কোন ছোট নাম্বার আছে ( স্ট্যাকে ) তাইলে সেই নাম্বারটা কারেন্ট নাম্বার এর পরের কোন ছোট নাম্বার এর জন্য কাজে লাগবে না (এমনকি সমান হলেও কিন্তু একই কথা হবে ), কারন কারেন্ট নাম্বার এই তো তার জন্য কাছের বড় নাম্বার হবে, তাই সেটি স্ট্যাক থেকে তুলে দিব, কিন্তু যদি দেখি আগের নাম্বারট কারেন্ট স্ট্যাক থেকে বড় তাইলে কিন্তু রাখা লাগবে কারন এমন হতেই পারে যে কারেন্ট নাম্বার এর পরের নাম্বারটাই কারেন্ট থেকে বড় কিন্তু স্ট্যাকের নাম্বার থেকে ছোট, তাই নাম্বার স্ট্যাক থেকে ফেলে দিলে আমরা পরে সেই নাম্বার এর জন্য বড় নাম্বার খুজে পাব না, আর যদি আমরা কখনো দেখি স্ট্যাক এর কোন নাম্বার আমরা নাম্বার থেকে বড় নাই, [ স্ট্যাক এম্পটি ] সেক্ষেত্রে আমারা বলতে পারি কোন নাম্বার এই বড় নাম্বার স্ট্যাকে নেই, যেকোন ফ্ল্যাগ ভেলু দিয়ে আমারা সেটাকে বুঝাতে পারি ( stack size() or -1 ); সব শেষে আমরা কারেন্ট ভ্যালুকে স্টাকে পুশ করব;

```cpp
vector<int> nearestLargerRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n); // Initialize result vector with n where no valid value is present
    stack<int> s; // stack to store indices of elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from stack while stack is not empty and
        // the top element is smaller than or equal to current element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the nearest larger element in right is stack top
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element's index onto the stack
        s.push(i);
    }

    return result;
}
```

একই ভাবে বামের বড় নাম্বার বের করতে হলে আমরা প্রথম থেকে নাম্বার ট্রাভার্স করা শুরু করব; এবং আমরা স্ট্যাক টপের নাম্বার, কারেন্ট নাম্বার থেকে ছোট হলে বাদ দিব; মূল লজিক আসলে ঠিক আগের মত করেই হবে; শুধু ট্রাভার্সাল হবে বাম থেকে ডানে;

```cpp
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> s; // Stack to store indices of elements

    for (int i = 0; i < n; ++i) {
        // Pop elements from stack while stack is not empty and
        // the top element is smaller than or equal to current element
        while (!s.empty() && arr[s.top()] <>= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the nearest larger element in left is the top element of the stack
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element's index onto the stack
        s.push(i);
    }

    return result;
}

```

---

## Sub Array, Substring vs Subsequence vs Subset

**Subarray:** A subarray is a contiguous sequence of elements within an array. For instance, the subarrays of the array {1, 2, 1} would be {1}, {2}, {1, 2}, {2, 1}, {1, 2, 1}, {}.

**Substring:** A substring is exactly the same thing as a subarray but in the context of strings. For instance, the substrings of the string "ara" would be "a", "r", "ar", "ra", "ara", "".

**Subsequence:** A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. This means a subsequence is a generalized subarray, where the rule of contiguity does not apply. For instance, the subsequences of the sequence <A, B, C> would be <A>, <B>, <A, B>, <B, C>, <A, C>, <A, B, C>, <>.

**Set:** A set is subset of another set if all its elements are contained by that set. This means, neither contiguity nor ordering of elements matter. For instance, the subsets of the set {1, 2, 3} would be {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}, {}.

**Comparison Table**
| property \ Element | Subarray | Substring | Subsequence | Subset |
|------------------|-----------|-------------|-------------|--------|
| Contiguous | Yes | Yes | No | No |
| Elements Ordered | Yes | Yes | Yes | No |
