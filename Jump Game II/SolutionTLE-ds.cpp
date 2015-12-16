#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        return jump_test(nums, 0);
    }
    int jump_test(vector<int>& nums,int start){
        if(nums.size()-1-start<=nums[start])
            return 1;
        else{
            int min = nums.size();
            for(int i=1;i<=nums[start];i++){
                int step = 1 + jump_test(nums,start+i);
                if(min>step)
                    min = step;
            }
            return min;
        }
    }
};
int main(){
    int a[5] = {2,3,1,1,4};
    vector<int> nums(a,a+5);
    Solution s;
    cout<<s.jump(nums);

}
