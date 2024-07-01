#include<bits/stdc++.h>

using namespace std;
vector<int> temp(1000);// used in merge sort

// int pivotSetter(vector<int>& nums, int lo, int hi){ // needed in quickSort
//     int pivot = nums[hi];
//     // i will set numbers smaller than pivot to left of last i position
//     int i, j;
//     for(i = lo-1,  j = lo; j < hi; j++){
//         if(nums[j] < pivot){
//             i++;
//             swap(nums[j],nums[i] );
//         }
//     }
//     // place pivot to i+1 pos
//     swap(nums[i+1], nums[hi]); // nums[hi] is pointing pivot;
//     return i+1; // the new place for pivot;
// }

// updated pivot setter; 
int pivotSetter(vector<int>& nums, int lo, int hi){ // needed in quickSort
    int pivot = nums[hi];
    // smaller number than pivot will be placed on ith position
    int i, j;
    for(i = lo, j = lo; j < hi; j++){
        if(nums[j] < pivot){
            swap(nums[j],nums[i] );
            i++;
        }
    }
    // i the position where i should stand in sorted order 
    swap(nums[i], nums[hi]); // nums[hi] is pointing pivot;
    return i; // the new place for pivot;
}

void quickSort(vector<int>& nums, int lo, int hi ){

    // all swaping will be in place
    //base case
    if ( lo >= hi ) return;

    int pivotIndex = pivotSetter(nums, lo, hi);

    quickSort(nums, lo, pivotIndex-1);
    quickSort(nums, pivotIndex+1, hi);


    return;

}

void bucketSort(vector<int>& nums){
    /* another interesting sorting algo
    ** non comparison based
    ** each bucket can be processed independently
    ** so allows parallelization; faster than other algo
            ** আমারা ঠিক করব কতগুলো বাকেট লাগবে এরপর সেই বাকেট গুলোয় শর্ত অনুযায়ী( প্রতি বাকেট এর রেঞ্জ থাকবে) নাম্বার ইন্সার্ট করব
            ** অনেক ভ্যারিয়েশন সম্ভব;
    */
    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());

    int range = maxVal - minVal + 1;
    vector<vector<int>> buckets(range,vector<int>());

    for(auto num : nums){
        buckets[num - minVal].push_back(num);
    }
    /*
            ** এখানে বাকেটস এর সংখ্যা রেঞ্জ এর সমান; এর ছোট হলে প্রত্যকে বাকেট এ আলাদা আলাদা ভাবে  সর্ট করা লাগতো
    // Sort individual buckets (using insertion sort)
    for (int i = 0; i < range; ++i) {
        if (!buckets[i].empty()) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
    }
    */

    nums.clear();
    for(auto bucket:buckets){
        for(auto it: bucket) nums.push_back(it);
    }
}

void countingSort(vector<int>& nums){
    /*
            ** অনলি সব নাম্বার পজিটিভ হলেই কাউন্টিং সর্ট করা যায়; এর জন্য আমরা মাক্স নাম্বারটা বের করব এর পর; ম্যাক্স সাইজের একটা ফ্রিকুয়েন্সি আরে বানাবো;
            ** পরে ফ্রেকুয়েন্সি অ্যারে থেকে নাম্বারগুলো ক্রমানুযায়ী বের করে নিব
    ** TLE O(n+N) যা O(nlogn) থেকে বেশিরভাগ ক্ষেত্রেই কম [ n-> size of array, N-> Range]
    */
    int maxi = *(max_element(nums.begin(), nums.end()));
    vector<int> range(maxi+1);

    for(auto num : nums){
        range[num]++;
    }
    nums.clear();
    for(int i = 0; i<maxi+1; i++ ){
        int freq = range[i];
        while(freq--){
            nums.push_back(i);
        }
    }
}

void mergeSort(vector<int>& nums, int lo, int hi ){
    /**
            ** ভেক্টরকে সমান দুই ভাগে ভেঙ্গে ফেলব এভাবে ভাংতেই থাকব যতক্ষন না একটা একটা করে আইটেম এর ভেক্টর হয়
            ** এর পর সেগুলো জোড়া দেবার পালা; একটা থেকে দুটো; দুটোর দুইটা জোড়া থেকে চারটার সাবভেক্টর;
            ** তবে ভাঙ্গার কাজটা মুলতো lo and hiকে দিয়ে হবে ওরাই ঠিক করে দিবে কতটুকু ভেক্টর এর উপর কাজ হবে;
    **/

    /**
    *** hi is index of right most number in vector;
    **/


    // base case
    if(lo == hi) return;

    int mid = lo + (hi - lo) / 2;
    // ভাংতে হবে
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid+1, hi);

    // এখানে আমার হাতে আছে lo, mid, hi
    //এবার জোড়া লাগাই
    for(int i = lo, j = mid+1, k = lo; k <= hi; k++){
        if     (i == mid + 1)   temp[k] = nums[j++];
        else if(j == hi  + 1)   temp[k] = nums[i++];
        else if(nums[i]<nums[j])temp[k] = nums[i++];
        else if(nums[j]<nums[i])temp[k] = nums[j++];
    }

    // copy sorted numbers from temp to nums
    for(int i = lo; i <= hi; i++){
        nums[i] = temp[i];
    }
}

void bubbleSort(vector<int>& nums){
    /*
            ** সিলেকশন সর্ট এ আমারা একটা নির্দিস্ট পজিশনের সাথে অন্য সকল পজিশনের কম্পেয়ার করি;
            ** বাট বাবল সর্ট শুধু পাশাপাশি কম্পেয়ার করেই সবচেয়ে বড় ভ্যালুকে প্রতি ইটারেশনে সবার উপরে উঠিয়ে দেয়;
    */

    for(int i = 1; i<nums.size(); i++){
        for( int j = 0; j<nums.size() - i; j++){
            if(nums[j ] > nums[j+1]) {// পাশাপাশি ভ্যলু লাস্ট ভ্যালু nums[j+1];
                swap(nums[j], nums[j+1]);
            }
        }
    }

}

void selectionSort(vector<int>& nums){

    /*
            **সবচাইতে সহজ সর্ট গুলোর মধ্যে একটা, প্রতি ইটারেশনে সবচেয়ে ছোট নাম্বারটা সবার প্রথমে চলে আসবে;
            ** সোয়াপ stlএই লিখা আছে; নট সিমিলার উইথ বাবল সর্ট;
    */

    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[i]>nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}

void insertionSort(vector<int>& nums){
    /*
            ** ছোটবেলা স্যার রা খাতা দেখানোর পর খাতা আবার সাজানোর জন্য ইন্সসারশন সর্ট করত;
            ** আগে হাতের খাতা গুলো সর্ট করে নিতাম এর পর নতুন একটা খাতা পূর্বের সর্ট করা খাতাগুলোর যেখানে বসানো উচিত
            ** সেখানে গিয়ে রেখে দিতাম
    */

    for(int i = 1; i < nums.size(); i++){
        // প্রতি ইটারেশনে x ই নতুন খাতা আর  j হল পূর্বের খাতা সংখ্যা
        int x = nums[i];
        int j = i - 1;

        while( j >= 0 and nums[j] > x){  // 1 0
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
}

void print (vector<int>& nums){
    for(auto it:nums) cout<<it<<" ";
}

int main() {
    vector<int> nums = {3,20,41,35,26,1,0};
    //mergeSort(nums,0,nums.size()-1);
    //bucketSort(nums);
    quickSort(nums,0,nums.size() - 1);
    print(nums);
}
