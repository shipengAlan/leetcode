#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse_x = 0;
        if(x<0)
            return false;
        else{
            int a = x;
            while(x!=0){
                reverse_x = reverse_x*10 + (long long)(x%10);
                x = x/10;
            }
            if(a==reverse_x)
                return true;
            else
                return false;
        }

    }
};
int main(){
    Solution s;
    cout<<s.isPalindrome(101);
}
