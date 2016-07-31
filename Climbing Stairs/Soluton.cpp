#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if(n==1)
            return a;
        else if(n==2)
            return b;
        else{
            for(int i=3;i<=n;i++){
                int t = a + b;
                a = b;
                b = t;
            }
            return b;
        }
    }
};
int main(){
    Solution s;
    cout<<s.climbStairs(4);
}
