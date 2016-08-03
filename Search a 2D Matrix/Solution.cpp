#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector< vector<int> > & matrix, int target) {
        int m = matrix.size();
        int n = 0;
        if(m>0){
            n = matrix[0].size();
        }
        cout<<m<<" "<<n<<endl;
        bool result = false;
        int i = 0;
        while(i<m){
            if(matrix[i][0]<=target&&matrix[i][n-1]>=target){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==target){
                        result = true;
                        break;
                    }
                }
                if(result==true)
                    break;
            }
            if(matrix[i][0]>target)
                break;
            i++;
        }
        return result;
    }
};
int main(){
    Solution s;
    vector< vector<int> >  matrix;
    int a[4] = {1,   3,  5,  7};
    vector<int> va(a, a+4);
    int b[4] = {10, 11, 16, 20};
    vector<int> vb(b, b+4);
    int c[4] = {23, 30, 34, 50};
    vector<int> vc(c, c+4);
    matrix.push_back(va);
    matrix.push_back(vb);
    matrix.push_back(vc);
    cout<<s.searchMatrix(matrix, 3);
}
