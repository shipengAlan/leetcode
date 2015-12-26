#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> perm;
        sort(nums.begin(),nums.end());
        internalpermuteUnique(nums, 0, perm, result);

        return result;
    }
    //从index开始，到最后数字的全排列。全排列的前缀
    void internalpermuteUnique(vector<int> &num, int index, vector<int> perm, vector<vector<int> > &result) {
        int size = num.size();

        if (size == index) {
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
                if ((i > index) && (num[i] == num[index])) {
                  continue;
                }
                else {
                  swap(num[index], num[i]);
                }

                perm.push_back(num[index]);
                internalpermuteUnique(num, index + 1, perm, result);
                perm.pop_back();
            }
            //恢复原来num的顺序，此时应该已经逆序
            sort(num.begin() + index, num.end());
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
