#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        set< vector<int> > set_nums;
        sort(nums.begin(),nums.end());
        vector< vector<int> > res;
        if(nums.size()<3)
            return res;
        int last = nums[0] - 1;
        for(int i=0;i<nums.size()-2;i++){
            if(last == nums[i])
                continue;
            int right = nums.size()-1;
            int left = i+1;
            while(left<right){
                if(nums[left]+nums[right]<-nums[i])
                    left++;
                else if (nums[left]+nums[right]>-nums[i])
                    right--;
                else{
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[left]);
                    item.push_back(nums[right]);
                    set_nums.insert(item);
                    left++;
                    right--;
                }
            }
            last = nums[i];
        }
        set< vector<int> >::iterator it;
        for(it=set_nums.begin();it != set_nums.end();it++)
            res.push_back(*it);
        return res;
    }
};
int main(){
    Solution s;
    int a[6] = {-1,0,1,2,-1,-4};
    vector<int> input(a,a+6);
    vector< vector<int> > res = s.threeSum(input);
    cout<<"hello"<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<3;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
