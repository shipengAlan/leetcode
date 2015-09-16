#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        if(x>0)
            sign = 1;
        else if(x<0)
            sign = -1;
        else
            sign = 0;
        x = abs(x);
        long long int result = 0;
        int temp = x;
        while(temp!=0){
            result *= 10;
            result += temp % 10;
            cout<<temp%10<<endl;
            temp = temp / 10;

        }
        return sign*result;
    }
};
int main(){
    Solution s;
    cout<<s.reverse(1534236469);
    return 0;
}
