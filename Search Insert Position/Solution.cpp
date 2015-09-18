#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle = (left+right)/2;
        while(left<=right){
            middle = (left+right)/2;
            if(nums[middle]==target)
                return middle;
            if(nums[middle]<target)
                left = middle+1;
            else
                right = middle-1;

        }
        if(target>nums[right]&&target<nums[middle]){
            return middle;
        }
        else
            return left;
    }
};
int main(){
    Solution s;
    vector<int> input;
    input.push_back(1);
    input.push_back(3);
    input.push_back(5);
    input.push_back(6);
    cout<<s.searchInsert(input,4);
}
