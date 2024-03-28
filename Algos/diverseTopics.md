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
