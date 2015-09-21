#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
class Solution {
public:
    vector< vector<int> > res;
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        search_tree(current,candidates,target,0);
        vector< vector<int> > tmp;
        set< vector<int> > set_tmp;
        for(int i=0;i<res.size();i++)
            set_tmp.insert(res[i]);
        set< vector<int> >::reverse_iterator rit;
        for(rit=set_tmp.rbegin();rit!=set_tmp.rend();rit++)
            tmp.push_back(*rit);
        return tmp;
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
    void search_tree(vector<int> current,vector<int> candidates,int target,int start){
        int length = current.size();
        for(int i=start;i<candidates.size();i++){
            if(length==0||candidates[i]>=current[length-1]){
                if(sum(current,candidates[i])==target){
                    vector<int> tmp = copy(current);
                    tmp.push_back(candidates[i]);
                    res.push_back(tmp);
                }
                if(sum(current,candidates[i])>target)
                    break;
                if(sum(current,candidates[i])<target){
                    cout<<"---"<<endl;
                    for(int x=0;x<current.size();x++)
                        cout<<current[x]<<" ";
                    cout<<endl;
                    cout << candidates[i]<<endl;
                    cout<<"---"<<endl;
                    vector<int> tmp = copy(current);
                    tmp.push_back(candidates[i]);
                    search_tree(tmp,candidates,target,i+1);
                }
            }

        }
    }
};
int main(){
    Solution s;
    int a[7] = {1,2};
    vector<int> candidates(a,a+2);
    vector< vector<int> > res = s.combinationSum(candidates,4);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
