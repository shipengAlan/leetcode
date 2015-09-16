#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        set< vector<int> > set_nums;
        sort(nums.begin(),nums.end());
        vector< vector<int> > res = subSum(nums,target,0,4);
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(), res[i].end());
            set_nums.insert(res[i]);
        }
        vector< vector<int> > res2;
        set< vector<int> >::iterator it;
        for(it=set_nums.begin();it != set_nums.end();it++)
            res2.push_back(*it);
        return res2;
    }
    vector< vector<int> > subSum(vector<int>& nums, int target, int start, int n){
        if(n==2){
            vector< vector<int> > res;
            int left = start;
            int right  = nums.size() - 1;
            if(left==right)
                return res;
            while(left<right){
                if(nums[left]+nums[right]<target){
                    left++;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    vector<int> item;
                    item.push_back(nums[left]);
                    item.push_back(nums[right]);
                    left++;
                    right--;
                    res.push_back(item);
                }
            }
            return res;
        }
        vector< vector<int> > res;
        for(int i=start;i<nums.size();i++){
            vector< vector<int> > temp = subSum(nums, target-nums[i], i+1, n-1);
            for(int j=0;j<temp.size();j++){
                temp[j].push_back(nums[i]);
                res.push_back(temp[j]);
            }

        }
        return res;
    }
};
int main(){
    Solution s;
    int a[6] = {-1,0,1,2,-1,-4};
    vector<int> input(a,a+6);
    vector< vector<int> > res = s.fourSum(input,0);
    cout<<"hello"<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<4;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

}
