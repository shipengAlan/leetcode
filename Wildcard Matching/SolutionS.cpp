#include<iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int ss = 0;
        int pp = 0;
        int tp = p.length();
        int ts = ss;
        while(ss<s.length()){
            cout<< ss <<" "<<pp<<endl;
            if(s[ss]==p[pp]||p[pp]=='?'){
                ss++;
                pp++;
            }
            else if(p[pp]=='*'){
                tp = pp;
                ts = ss;
                pp++;
            }
            else if(tp<p.length()){
                ts++;
                ss = ts;
                pp = tp + 1;
            }
            else{
                return false;
            }
        }
        cout<<pp<<endl;
        while(p[pp]=='*') pp++;
        if(pp==p.length())
            return true;
        else
            return false;
    }

};
int main(){
    Solution s;
    cout<<s.isMatch("aab","?**")<<endl;

}
