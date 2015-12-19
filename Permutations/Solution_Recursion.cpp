#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > res;
        if(nums.size()==1)
        {
            res.push_back(nums);
            return res;
        }
        vector<int> cur;
        vector< vector<int> > cur_res;
        for(int i=0;i<nums.size();i++){
            cur = nums;
            cur.erase(cur.begin()+i);
            cur_res = permute(cur);
            for(int j=0;j<cur_res.size();j++){
                vector<int> tmp = cur_res[j];
                tmp.insert(tmp.begin(),nums[i]);
                res.push_back(tmp);
            }
        }
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
