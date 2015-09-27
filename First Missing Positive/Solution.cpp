#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        //在原数组上建 索引
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>0&&nums[i]!=i+1&&nums[i]-1<nums.size()&&nums[nums[i]-1]!=nums[i]){
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1)
                return i+1;
        return nums[nums.size()-1]+1;
    }
};
int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(-1);
    cout<<s.firstMissingPositive(nums);
}
