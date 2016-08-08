#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        int * state = new int[nums.size()];
        memset(state, 0, sizeof(int)* nums.size());
        vector< vector<int> > result;
        for(int i=0;i<pow(2,nums.size());i++){
            int c = 1;
            for(int j=0;j<nums.size();j++){
                if(c==1&&state[j]==1){
                    state[j]=0;
                    c = 1;
                }
                else if(c==0){
                    break;
                }
                else{
                    state[j]=1;
                    c = 0;
                }
            }
            vector<int> t;
            for(int j=0;j<nums.size();j++){
                if(state[j]==1){
                    t.push_back(nums[j]);
                }
            }
            result.push_back(t);
        }
        return result;
    }
};
int main(){
    Solution s;
    int a[5] = {1,2,3,4,5};
    vector<int> input(a, a+5);
    s.subsets(input);
}
