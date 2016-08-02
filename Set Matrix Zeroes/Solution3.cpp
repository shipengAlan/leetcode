#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
�������matrix[i][j]��0����ô���ǾͰ�matrix[0][j]��matrix[i][0]��Ϊ0����ʱ��ֻҪ�鿴���������Ϳ���֪��i�к�j��Ӧ�ñ�Ϊ0��
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
