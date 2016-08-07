#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > result;

        for(int i=1;i<=n;i++){
                vector<int> t;
                t.push_back(i);
                result.push_back(t);
        }
        if(k==1){
            return result;
        }
        int i = 1;
        while(i<k){
            vector< vector<int> > temp;
            for(int j=0;j<result.size();j++){
                int s = result[j][i-1];
                for(int e=s+1;e<=n;e++){
                    vector<int> t(result[j]);
                    t.push_back(e);
                    temp.push_back(t);
                }
            }
            //result.clear();
            result = temp;
            //result.assign(temp.begin(), temp.end());;
            //temp.clear();
            i++;
        }
        /*
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<",";
            }
            cout<<endl;
        }
        */
        return result;
    }
};
int main(){
    Solution s;
    s.combine(20,16);
}
