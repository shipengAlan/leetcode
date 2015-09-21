#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    vector< vector<int> > res;
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        search_tree(current,candidates,target);
        return res;
    }
    int sum(vector<int> nums, int num){
        int res = 0;
        for(int i=0;i<nums.size();i++)
            res+=nums[i];
        res += num;
        return res;
    }
    vector<int> copy(vector<int> nums){
        vector<int> res;
        for(int i=0;i<nums.size();i++)
            res.push_back(nums[i]);
        return res;
    }
    void search_tree(vector<int> current,vector<int> candidates,int target){
        int length = current.size();
        for(int i=0;i<candidates.size();i++){
            if(length==0||candidates[i]>=current[length-1]){
                if(sum(current,candidates[i])==target){
                    vector<int> tmp = copy(current);
                    tmp.push_back(candidates[i]);
                    res.push_back(tmp);
                }
                if(sum(current,candidates[i])>target)
                    break;
                if(sum(current,candidates[i])<target){
                    vector<int> tmp = copy(current);
                    tmp.push_back(candidates[i]);
                    search_tree(tmp,candidates,target);
                }
            }

        }
    }
};
int main(){
    Solution s;
    int a[4] = {2,3,6,7};
    vector<int> candidates(a,a+4);
    vector< vector<int> > res = s.combinationSum(candidates,7);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
