#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > result;
        if(k==1){
            for(int i=1;i<=n;i++){
                vector<int> t;
                t.push_back(i);
                result.push_back(t);
            }
            return result;
        }
        else{
            vector< vector<int> > temp = combine(n-1,k-1);
            for(int i=0;i<temp.size();i++){
                int s = temp[i][temp[i].size()-1];
                for(int j=s+1;j<=n;j++){
                    vector<int> tmp(temp[i]);
                    result.push_back(tmp);
                    int t = result.size()-1;
                    result[t].push_back(j);

                }
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector< vector<int> > result = s.combine(20,16);
    /*
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
    */
}
