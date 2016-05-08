#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        int m=0,n=0;
        m = matrix.size();// m row
        if(m > 0)
            n = matrix[0].size();
        int i=0,j=0;
        int state =0;
        int s_r=0;
        int s_c=0;
        int e_r = m-1;
        int e_c = n-1;
        vector<int> result;
        while(result.size()<m*n){
            result.push_back(matrix[i][j]);
            if(j==e_c&&state==0){
                state=1;
            }
            if(i==e_r&&state==1){
                state=2;
            }
            if(j==s_c&&state==2){
                state=3;
            }
            if(i==s_r+1&&state==3){
                state=0;
                e_r--;
                e_c--;
                s_c++;
                s_r++;
            }
            if(state==0)
                j++;
            if(state==1)
                i++;
            if(state==2)
                j--;
            if(state==3)
                i--;
        }
        return result;
    }
};
int main(){


}
