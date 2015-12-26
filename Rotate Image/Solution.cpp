#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        int s = matrix.size()
        for(int i=0;i<s;i++){
            for(int j=0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0;i<s;i++){
            int k = s - i -1;
            if(i < k){
                for(int j=0;j<s;j++){
                    int temp = matrix[j][i];
                    matrix[j][i] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }
    }
};
