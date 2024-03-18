#include<bits/stdc++.h>
using namespace std;
int used[20], number[20];

void permutation (int at, int n){
    if( at == n+1){
        for(int i = 1; i <= n; i++){
            if(number[i]) printf("%d", number[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            number[at] = i;
            permutation(at+1, n);
            used[i] = 0;
        }
    }
}


void print (vector<int>& nums){
    for(auto it:nums) cout<<it<<" ";
}


int main() {
    vector<int> nums = {3,20}; //{3,20,41,35,26,1,0};
    permutation(1,3);// that is 3P3 [nPr]

}
