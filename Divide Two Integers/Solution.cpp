#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int MAX_INT = 0x7fffffff;
        int MIN_INT = 0x80000000;
        int res = 0;
        int sign1 = 1;
        int sign2 = 1;
        long long Divisor = divisor;
        long long Dividend = dividend;
        if(Divisor==0)
            return MAX_INT;
        if(Dividend<0){
            sign1 = -1;
            Dividend = -1*Dividend;
        }

        if(Divisor<0){
            sign2 = -1;
            Divisor = -1*Divisor;
        }
        while(Dividend>0){
            long long i=1;
            long long base = Divisor;
            while(Dividend>base){
                i=i<<1;
                base=base<<1;
            }
            if(base>Dividend){
                base=base>>1;
                i=i>>1;
            }
            res += i;
            Dividend-=base;
        }
        res = res*sign1*sign2;
        if(res>MAX_INT||res<MIN_INT)
            return MAX_INT;
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.divide(1,2);
}
