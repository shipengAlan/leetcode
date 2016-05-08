#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int cur_max = nums[0];
        int max = nums[0];
        for(int i=1;i<nums.size();i++){
            cur_max = nums[i] > cur_max+nums[i]? nums[i] : cur_max+nums[i];
            if(cur_max > max)
                max = cur_max;
        }
        return max;
    }
};

int main(){
    Solution s;
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr,arr+9);
    cout<<s.maxSubArray(nums);
}
