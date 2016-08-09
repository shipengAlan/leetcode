#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()>0){
            int last = nums[0];
            int i = 1;
            int count = 1;
            while(i<nums.size()){
                if(nums[i]==last){
                    if(count==1){
                        count++;
                        i++;
                    }
                    else{
                        nums.erase(nums.begin()+i);
                    }
                }
                else{
                    last = nums[i];
                    count = 1;
                    i++;

                }
            }
            return nums.size();
        }
        else{
            return 0;
        }
    }
};
int main(){
    Solution s;
    int a[2] = {1,2};
    vector<int> nums(a, a+2);
    cout<<s.removeDuplicates(nums);
}
