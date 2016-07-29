#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long l=1;
        long long r=x;
        long long c=0;
        while(l<=r){
            //cout<<c<<endl;
            c = (l + r)/2;
            if(c*c<x){
                l = c+1;
            }
            else if(c*c>x){
                r = c-1;
            }
            else{
                return c;
            }
        }
        return r;
    }
};
int main(){
    Solution s;
    cout<<s.mySqrt(2147483647);
    //for(int i=1;i<100;i++)
    //    cout<<i<<" "<<s.mySqrt(i)<<endl;
}
