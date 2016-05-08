#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_index = 0;
        int step = nums[cur_index]+cur_index;
        while(1){
            int max = 0;
            if(cur_index>=nums.size()-1)
                return true;
            for(int i=cur_index+1;i<=step;i++){
                if(i>=nums.size()-1)
                    return true;
                if(max<nums[i]+i)
                    max=nums[i]+i;
            }
            cur_index = step;
            if(step==max)
                return false;
            step = max;
        }
    }
};
int main(){
    int arr[5] = {2,3,1,1,4};//{3,2,1,0,4};//
    vector<int> nums(arr,arr+5);
    Solution s;
    cout<<s.canJump(nums);


}
