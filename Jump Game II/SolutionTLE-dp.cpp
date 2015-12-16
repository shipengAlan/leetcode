#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int *d = new int[nums.size()];
        d[0] = 0;
        for(int i=1;i<nums.size();i++){
            d[i] = nums.size();
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i){
                    if(d[i]>d[j]+1){
                        d[i]=d[j]+1;
                    }
                }
            }
        }
        return d[nums.size()-1];
    }
};
int main(){
    int a[5] = {2,3,1,1,4};
    vector<int> nums(a,a+5);
    Solution s;
    cout<<s.jump(nums);

}
