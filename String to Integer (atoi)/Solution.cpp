#include<iostream>
using namespace std;
class Solution {
public:
    bool isDigit(char c){
        if(c>='0'&&c<='9')
            return true;
        else
            return false;
    }
    int myAtoi(string str) {
        const static int _INT_MAX = 0x7fffffff;
        const static int _INT_MIN = 0x80000000;
        int i = 0;
        long long num = 0;
        int sym = 1;
        while(str[i]==' ')
            i++;
        if(str[i]=='-'||str[i]=='+'||isDigit(str[i])){
            if(str[i]=='-'||str[i]=='+'){
               if(str[i]=='-')
                    sym = -1;
               i++;
            }
            while(i<str.size()){
                if(isDigit(str[i])){
                    num = num*10 + (str[i]-'0');
                    if(num>_INT_MAX){
                        if(num*sym>0)
                            return _INT_MAX;
                        else
                            return _INT_MIN;
                    }
                    i++;
                }
                else
                    break;
            }
        }
        return (int)num*sym;
    }
};
int main(){
    Solution s;
    cout<<s.myAtoi("-2147483648");
}
