#include<iostream>
using namespace std;
# 这道题可以用动态规划，用排列组合的方法容易越界
class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        if(m==0||n==0)
            return 1;
        int a,b;
        if(m>n){
            a = m;
            b = n;
        }
        else{
            a = n;
            b = m;
        }
        int j = 1;
        long long up = 1;
        for(int i=a+b;i>=a+1;i--){
            up *= i;
            if(j<=b){
                up /= j;
                j++;
            }
            //cout<<"^"<<up<<endl;
        }
        while(j<=b){
            up /= j;
            j++;
        }
        return up;
    }
};
int main(){
    Solution s;
    cout<<s.uniquePaths(20,20)<<endl;
    cout<<s.uniquePaths(30,30)<<endl;
    cout<<s.uniquePaths(40,40)<<endl;
    cout<<s.uniquePaths(50,50)<<endl;
    cout<<s.uniquePaths(60,60)<<endl;
    //cout<<s.uniquePaths(70,70)<<endl;
}

