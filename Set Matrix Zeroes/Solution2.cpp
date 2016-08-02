#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        int r = matrix.size();
        int c = 0;
        if(r!=0){
            c = matrix[0].size();
        }
        int * r_v = new int[r];
        int * c_v = new int[c];
        memset(r_v, 0, sizeof(int)*r);
        memset(c_v, 0, sizeof(int)*c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    r_v[i]=1;
                    c_v[j]=1;
                }
            }
        }
        for(int i=0;i<r;i++){
            if(r_v[i]==1){
                for(int j=0;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<c;j++){
            if(c_v[j]==1){
                for(int i=0;i<r;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
int main(){
    Solution s;
    //s.setZeroes();
}
