#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        int label0 = 0;
        int label1 = 0;
        int label2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                num0++;
                nums[label0] = 0;
                label0++;
                if(num1>0){
                    nums[label1] = 1;
                }
                if(num2>0){
                    nums[label2] = 2;
                }
                label1++;
                label2++;

            }
            else if(nums[i]==1){
                num1++;
                nums[label1] = 1;
                label1++;
                if(num2>0){
                    nums[label2] = 2;
                }
                label2++;

            }
            else if(nums[i]==2){
                num2++;
                nums[label2] = 2;
                label2++;
            }
            for(int j=0;j<nums.size();j++){
                cout<<nums[j]<<" ";
            }
            cout<<endl;
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

