#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > result;
        if(nums.size()==0){
            vector<int> t;
            result.push_back(t);
            return result;
        }
        else{
            vector<int> tmp(nums);
            int last = nums[nums.size()-1];
            tmp.erase(tmp.begin()+nums.size()-1);
            result = subsets(tmp);
            int s = result.size();
            for(int i=0;i<s;i++){
                vector<int> t(result[i]);
                t.push_back(last);
                result.push_back(t);
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    int a[5] = {1,2,3,4,5};
    vector<int> input(a, a+5);
    vector< vector<int> > result = s.subsets(input);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
