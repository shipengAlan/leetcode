#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
比如如果matrix[i][j]是0，那么我们就把matrix[0][j]和matrix[i][0]变为0，到时候只要查看这两个数就可以知道i行和j列应该变为0。
*/
class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        int r = matrix.size();
        int c = 0;
        if(r!=0){
            c = matrix[0].size();
        }
        int z_r = 1;
        int z_c = 1;
        for(int j=0;j<c;j++){
            if(matrix[0][j]==0){
                z_r = 0;
            }
        }
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0){
                z_c = 0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<r;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<c;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<r;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(z_r==0){
            for(int j=0;j<c;j++){
                matrix[0][j]=0;
            }
        }
        if(z_c==0){
            for(int i=0;i<r;i++){
                matrix[i][0]=0;
            }
        }
    }
};
int main(){
    Solution s;
    //s.setZeroes();
}
