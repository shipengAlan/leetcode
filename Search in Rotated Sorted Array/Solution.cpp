#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle = (left+right)/2;
        while(left<=right){
            //cout<<left<<"   "<<middle<<"   "<<right<<endl;
            //cout<<nums[left]<<"   "<<nums[middle]<<"   "<<nums[right]<<endl;
            if(nums[middle]>=nums[left]){
                if(target>=nums[left]&&target<=nums[middle]){
                    int l = left;
                    int r = middle;
                    int m = (l+r)/2;
                    while(l<=r){
                        if(nums[m]==target){
                            return m;
                        }
                        else if(nums[m]>target)
                            r = m-1;
                        else
                            l = m+1;
                        m = (l+r)/2;
                    }
                    return -1;
                }
                left=middle+1;
            }
            if(nums[middle]<=nums[right]){
                if(target>=nums[middle]&&target<=nums[right]){
                    int l = middle;
                    int r = right;
                    int m = (l+r)/2;
                    while(l<=r){
                        if(nums[m]==target){
                            return m;
                        }
                        else if(nums[m]>target)
                            r = m-1;
                        else
                            l = m+1;
                        m = (l+r)/2;
                    }
                    return -1;
                }
                right=middle-1;
            }
            middle = (left+right)/2;
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    cout<<s.search(a,0)<<endl;
}
/*
for(int i=0;i<nums.size();i++)
            if(nums[i]==target)
                return i;
        return -1;
*/
