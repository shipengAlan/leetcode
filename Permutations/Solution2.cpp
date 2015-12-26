#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //从index开始，到最后数字的全排列。全排列的前缀
    void internalPermute(vector<int> &num, int index, vector<int> perm, vector<vector<int> > &result) {
        int size = num.size();

        if (size == index) {
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
                swap(num[index], num[i]);
                perm.push_back(num[index]);
                internalPermute(num, index + 1, perm, result);
                perm.pop_back();
                swap(num[index], num[i]);
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> perm;

        internalPermute(num, 0, perm, result);

        return result;
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
