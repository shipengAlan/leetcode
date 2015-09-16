#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)
            return "";
        string maxsubstr = s.substr(0,1);
        for(int i=0;i<s.length();i++){
            //ji
            int l = i;
            int r = i;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            string temp1 = s.substr(l,(i-l)*2+1);
            if(temp1.length()>maxsubstr.length())
                maxsubstr = temp1;
            //ou
            l = i;
            r = i+1;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            string temp2 = s.substr(l,r-l+1);
            if(temp2.length()>maxsubstr.length())
                maxsubstr = temp2;
        }
        return maxsubstr;
    }
};
int main(){
    Solution s;
    cout<<s.longestPalindrome("adaacbaac");
}
