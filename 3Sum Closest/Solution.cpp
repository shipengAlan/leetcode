#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i=0;i<3;i++)
            res += nums[i];
        int last = nums[0] - 1;
        for(int i=0;i<nums.size()-2;i++){
            if(last == nums[i])
                continue;
            int right = nums.size()-1;
            int left = i+1;
            while(left<right){
                int temp = nums[left]+nums[right]+nums[i];
                if(abs(temp-target)<abs(res-target))
                    res = temp;
                if(nums[left]+nums[right]+nums[i]<target)
                    left++;
                else if (nums[left]+nums[right]+nums[i]>target)
                    right--;
                else{
                    left++;
                    right--;
                }

            }
            last = nums[i];
        }
        return res;
    }
};
int main(){
    Solution s;
    int a[4] = {-1,2,1,-4};
    vector<int> input(a,a+4);
    cout<<s.threeSumClosest(input,1);
}
