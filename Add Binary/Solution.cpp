#include<iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1;
        int c=0,r=0;
        string result;
        while(i>=0||j>=0){
            if(i>=0&&j>=0){
                c = ((a[i]-'0') + (b[j]-'0') + r) % 2;
                r = ((a[i]-'0') + (b[j]-'0') + r) / 2;
                result = (char)(c + '0') + result;
            }
            else if(i>=0){
                c = ((a[i]-'0') + r) % 2;
                r = ((a[i]-'0') + r) / 2;
                result = (char)(c + '0') + result;
            }
            else if(j>=0){
                c = ((b[j]-'0') + r) % 2;
                r = ((b[j]-'0') + r) / 2;
                result = (char)(c + '0') + result;
            }
            i--;
            j--;
        }
        if(r==1)
            result = '1' + result;
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.addBinary("1010", "1011");

}
