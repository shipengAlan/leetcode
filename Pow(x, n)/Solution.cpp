#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            if(n==INT_MIN)
                return 1.0 / (myPow(x,INT_MAX)*x);
            return 1.0/myPow(x,-n);
        }
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        double result = 1;
        double pow = x;
        while(n!=0){
            if(n&1) result *= pow;
            pow *= pow;
            n=n>>1;
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.myPow(2.0,10);

}
