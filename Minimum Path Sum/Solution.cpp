#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        int max = 0x7fffffff;
        int r = grid.size();
        int c = 0;
        if(r>0){
            c = grid[0].size();
            if(c==0)
                return 0;
        }
        else
            return 0;
        int ** s = new int *[r];
        for(int i=0;i<r;i++){
            s[i] = new int[c];
            for(int j=0;j<c;j++)
                s[i][j] = max;
        }
        // init
        //cout<<"init"<<endl;
        s[0][0] = grid[0][0];
        for(int j=1;j<c;j++)
            s[0][j] = grid[0][j] + s[0][j-1];
        for(int i=1;i<r;i++)
            s[i][0] = grid[i][0] + s[i-1][0];
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++)
                s[i][j] = min(s[i-1][j],s[i][j-1]) + grid[i][j];
        }
        int result = s[r-1][c-1];
        for(int i=0;i<r;i++){
             delete [] s[i];
        }
        delete [] s;
        return result;
    }
};
int main(){
    Solution s;
    vector< vector<int> > obstacleGrid;
    vector<int> a;
    a.push_back(-1);
    a.push_back(3);
    a.push_back(2);
    vector<int> b;
    b.push_back(-2);
    b.push_back(-9);
    b.push_back(2);
    vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(-8);
    obstacleGrid.push_back(a);
    obstacleGrid.push_back(b);
    obstacleGrid.push_back(c);
    cout<<s.minPathSum(obstacleGrid);
}
