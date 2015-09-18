#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> res;
        int range_left=-1;
        int range_right=-1;
        int index = subSearch(nums,left,right,target);
        //cout<<index<<endl;
        if(index==-1){
            res.push_back(range_left);
            res.push_back(range_right);
        }
        else{
            range_left = index;
            range_right = index;
            int left_index = index-1;
            int right_index = index+1;
            while(1){
                int l = subSearch(nums,left,left_index,target);
                int r = subSearch(nums,right_index,right,target);
                if(l==-1&&r==-1)
                    break;
                if(l!=-1&&l<range_left){
                    range_left = l;
                    left_index = l-1;
                }

                if(r!=-1&&r>range_right){
                    range_right = r;
                    right_index = r+1;
                }

            }
            res.push_back(range_left);
            res.push_back(range_right);
        }
        return res;
    }
    int subSearch(vector<int>&nums, int l, int r, int target){
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target)
                return m;
            if(nums[m]<target)
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> input;
    input.push_back(5);
    input.push_back(7);
    input.push_back(7);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(10);
    vector<int> res = s.searchRange(input,7);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}
