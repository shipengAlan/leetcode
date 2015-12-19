#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > Q;
        Q.push_back(nums);
        int depth = nums.size();
        for(int k=0;k<depth;k++){
            vector< vector<int> > tmpQ;
            for(int j=0;j<Q.size();j++){
                for(int i=k;i<nums.size();i++){
                    vector<int> node = swap(Q[j],k,i);
                    tmpQ.push_back(node);
                }
            }
            Q.clear();
            Q = tmpQ;
            tmpQ.clear();
        }
        return Q;
    }
    vector<int> swap(vector<int>input, int a,int b){
        vector<int> res = input;
        int tmp = res[a];
        res[a] = res[b];
        res[b] = tmp;
        return res;
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
