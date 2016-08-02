#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        int r = matrix.size();
        int c = 0;
        if(r!=0){
            c = matrix[0].size();
        }
        vector<int> r_v;
        vector<int> c_v;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    r_v.push_back(i);
                    c_v.push_back(j);
                }
            }
        }
        for(int i=0;i<r_v.size();i++){
            for(int j=0;j<r;j++){
                matrix[j][c_v[i]]=0;
            }
            for(int j=0;j<c;j++){
                matrix[r_v[i]][j]=0;
            }
        }
    }
};
int main(){
    Solution s;
    s.setZeroes();
}
