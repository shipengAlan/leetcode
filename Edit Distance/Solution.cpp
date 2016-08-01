#include<iostream>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int max = 0x7fffffff;
        int r = word1.size();
        int c = word2.size();
        int ** d =  new int * [r+1];
        for(int i=0;i<=r;i++){
            d[i] = new int [c+1];
            for(int j=0;j<=c;j++)
                d[i][j] = max;
        }
        //initial
        for(int i=0;i<=r;i++){
            d[i][0] = i;
        }
        for(int j=1;j<=c;j++){
            d[0][j] = j;
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(word1[i-1]==word2[j-1])
                    d[i][j] = d[i-1][j-1];
                else
                    d[i][j] = min(min(d[i-1][j-1], d[i-1][j]), d[i][j-1]) + 1;
            }
        }
        return d[r][c];
    }
};
int main(){
    Solution s;
    cout<<s.minDistance("abc", "acbc");
}
