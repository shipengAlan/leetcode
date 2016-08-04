#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                num0 ++;
            if(nums[i]==1)
                num1 ++;
            if(nums[i]==2)
                num2 ++;
        }
        for(int i=0;i<nums.size();i++){
            if(num0>0){
                nums[i] = 0;
                num0--;
            }
            else if(num1>0){
                nums[i] = 1;
                num1--;
            }
            else if(num2>0){
                nums[i] = 2;
                num2--;
            }
        }
    }
};
int main(){
    Solution s;
    int a[5] = {0,2,1,2,0};
    vector<int> input(a, a+5);
    s.sortColors(input);
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
