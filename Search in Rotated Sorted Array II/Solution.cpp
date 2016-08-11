#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return subsearch(nums, target, 0, nums.size()-1);
    }
    bool subsearch(vector<int>& nums, int target, int l, int r){
        int m = (l+r)/2;
        if(l==r){
            return (target==nums[m]);
        }
        if(l<r){
           if(nums[l]>nums[r]){
                if(nums[m]>=nums[l]){
                    if(target>nums[m]){
                        return subsearch(nums, target, m+1, r);//l = m+1;
                    }
                    else if(target<nums[m]){
                        if(target>nums[l])
                            return subsearch(nums, target, l, m-1);//r = m-1;
                        else if(target<nums[l])
                            return subsearch(nums, target, m+1, r);//l = m+1;
                        else
                            return true;
                    }
                    else{
                        return true;
                    }
                }
                if(nums[m]<=nums[r]){
                    if(target<nums[m]){
                        return subsearch(nums, target, l, m-1);//r = m-1;
                    }
                    else if(target>nums[m]){
                        if(target>nums[r])
                            return subsearch(nums, target, l, m-1);//;r = m-1;
                        else if(target<nums[r])
                            return subsearch(nums, target, m+1, r);//l = m+1;
                        else
                            return true;
                    }
                    else{
                        return true;
                    }
                }
            }
            else if(nums[l]<nums[r]){
                if(nums[m]<target)
                    return subsearch(nums, target, m+1, r);//l = m+1;
                else if(nums[m]>target)
                    return subsearch(nums, target, l, m-1);//r = m-1;
                else
                    return true;
            }
            else{
                if(nums[m]>nums[l]){
                    if(target>nums[l]){
                        if(nums[m]>target)
                            return subsearch(nums, target, l, m-1);
                        else if(nums[m]<target)
                            return subsearch(nums, target, m+1, r);
                        else
                            return true;
                    }
                    else if(target<nums[l]){
                        return subsearch(nums, target, m+1, r);
                    }
                    else
                        return true;
                }
                else if(nums[m]<nums[l]){
                    if(target>nums[l]){
                        return subsearch(nums, target, l, m-1);
                    }
                    else if(target<nums[l]){
                        if(nums[m]>target)
                            return subsearch(nums, target, l, m-1);
                        else if(nums[m]<target)
                            return subsearch(nums, target, m+1, r);
                        else
                            return true;
                    }
                    else
                        return true;
                }
                else{
                    if(nums[m]==target){
                        return true;
                    }
                    else {
                        if(subsearch(nums, target, l, m-1))
                            return true;
                        if(subsearch(nums, target, m+1, r))
                            return true;
                        return false;
                    }
                }

            }
        }
        return false;
    }
};
int main(){
    Solution s;
    //int a[7] = {4,5,6,7,0,1,2};
    //int a[2] = {3,1};
    int a[7] = {1,2,2,2,0,1,1};
    vector<int> input(a, a+7);
    cout<<s.search(input, 0);
}
