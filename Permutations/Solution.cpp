#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > Q;
        for(int i=0;i<factorial(nums.size());i++){
            Next_permutation(nums);
            Q.push_back(nums);
        }
        return Q;
    }
    void Next_permutation(vector<int> &input){
        int i = input.size()-1;
        while(i>0&&input[i-1]>input[i]) i--;
        int j = i;
        while(j<input.size()&&input[i-1]<input[j]) j++;
        if(i==0){
            reverse(input.begin(),input.end());
        }
        else{
            swap(input[i-1],input[j-1]);
            reverse(input.begin()+i,input.end());
        }
    }
    int factorial(int n){
        if(n==1)
            return 1;
        else{
            return factorial(n-1)*n;
        }
    }
};
int main(){
    int a[4] = {1,2,3,4};
    vector<int> nums(a,a+4);
    Solution s;
    vector< vector<int> > res = s.permute(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
}
