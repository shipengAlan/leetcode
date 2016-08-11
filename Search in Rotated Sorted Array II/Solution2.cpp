#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return subsearch(nums, target, 0, nums.size()-1);
    }
    bool subsearch(vector<int>& nums, int target, int l, int r){
        int m = (l+r)/2;
        if(l==r){
            return (target==nums[m]);
        }
        if(l<r){
            if(nums[m]==target)
                return true;
            if(nums[m]>nums[l]){
                if(nums[l]<=target&&target<nums[m]){
                    return subsearch(nums, target, l, m-1);
                }
                else{
                    return subsearch(nums, target, m+1, r);
                }
            }
            else if(nums[m]<nums[l]){
                if(nums[m]<target&&target<=nums[r]){
                    return subsearch(nums, target, m+1, r);
                }
                else{
                    return subsearch(nums, target, l, m-1);
                }
            }
            else{
                return subsearch(nums, target, l+1, r);
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    //int a[7] = {4,5,6,7,0,1,2};
    //int a[2] = {3,1};
    int a[7] = {1,2,2,2,0,1,1};
    vector<int> input(a, a+7);
    cout<<s.search(input, 0);
}
