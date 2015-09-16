#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* method 1
        vector<int>::iterator it;
        it = nums.begin();
        while(it!=nums.end()){
            if(*it!=val)
                it++;
            else{
                nums.erase(it);
            }
        }
        return nums.size();
        */
        // method 2
        int start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[start] = nums[i];
                start++;
            }
        }
        return start;
    }
};
