#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int temp = nums[0] - 1;
        int length = 0;
        vector<int>::iterator it=nums.begin();
        while(it!=nums.end()){
            if(*it!=temp){
                length++;
                temp = *it;
                it++;
            }
            else{
                nums.erase(it);
            }
        }
        return length;
    }
};
int main(){
    int input[2] = {1,2};
    vector<int> iv(input,input+2);
    Solution s;
    cout<<s.removeDuplicates(iv);
}
