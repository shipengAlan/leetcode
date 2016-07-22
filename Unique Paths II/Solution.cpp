#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
         int r = obstacleGrid.size();
         int c = 0;
         if(r>0){
            c = obstacleGrid[0].size();
            if(c==0)
                return 1;
         }
         else
            return 1;
         int ** s = new int *[r];
         for(int i=0;i<r;i++){
            s[i] = new int[c];
            for(int j=0;j<c;j++)
                s[i][j] = 0;
         }
         // init
         //cout<<"init"<<endl;
         if(obstacleGrid[0][0]==0)
             s[0][0] = 1;
         for(int j=1;j<c;j++){
            if(obstacleGrid[0][j]==1)
                 continue;
            if(obstacleGrid[0][j-1]==0)
                s[0][j] = s[0][j-1];
         }
         for(int i=1;i<r;i++){
            if(obstacleGrid[i][0]==1)
                continue;
            if(obstacleGrid[i-1][0]==0)
                s[i][0] = s[i-1][0];
         }
         for(int j=1;j<c;j++){
            for(int i=1;i<r;i++){
                if(obstacleGrid[i][j]==1)
                    continue;
                if(obstacleGrid[i-1][j]==0)
                    s[i][j] += s[i-1][j];
                if(obstacleGrid[i][j-1]==0)
                    s[i][j] += s[i][j-1];
            }
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
    a.push_back(0);
    /*
    a.push_back(0);
    a.push_back(0);
    vector<int> b;
    b.push_back(0);
    b.push_back(1);
    b.push_back(0);
    vector<int> c;
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    */
    obstacleGrid.push_back(a);
    //obstacleGrid.push_back(b);
    //obstacleGrid.push_back(c);
    cout<<s.uniquePathsWithObstacles(obstacleGrid);
}
