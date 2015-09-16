#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tag = -1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]){
                tag = i;
            }
        }
        if(tag==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            for (int i = nums.size()-1; i > tag; i--) {
                if (nums[i] > nums[tag]) {
                    int tmp = nums[tag];
                    nums[tag] = nums[i];
                    nums[i] = tmp;
                    break;
            }
        }
        }
        reverse(nums.begin()+tag+1, nums.end());
    }
};
int main(){
    Solution s;
    vector<int> in;
    in.push_back(5);
    in.push_back(4);
    in.push_back(7);
    in.push_back(5);
    in.push_back(3);
    in.push_back(2);
    s.nextPermutation(in);
    for(int i=0;i<in.size();i++)
        cout<<in[i]<<endl;
}
