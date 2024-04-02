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

১। ঘর গুলো নিচের বাম থেকে উপরে ডানে উঠলে row + colmn কোনাকুনি লাইন টার জন্য নির্দিষ্ট থাকে
২। ঘর গুলো নিচের ডান থেকে বামে উপরে উঠলে row - colmn কোনাকুনি লাইন টার জন্য নির্দিষ্ট থাকে

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
