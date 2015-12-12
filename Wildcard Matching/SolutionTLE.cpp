#include<iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0&&p.size()==0)
            return true;
        if(s.size()!=0&&p.size()==0)
            return false;
        cout<<s<<"---"<<p<<endl;
        if(s.size()==0){
            if(p[0]=='*'){
                return isMatch(s,p.substr(1,p.size()-1));
            }else{
                return false;
            }
        }
        if(p[0]=='*'){
            for(int i=0;i<=s.size();i++){
                bool temp = isMatch(s.substr(i,s.size()-i),p.substr(1,p.size()-1));
                cout<<"#"<<temp<<endl;
                if(temp==true)
                    return true;
            }
            return false;
        }
        else if(p[0]=='?'||s[0]==p[0]){
            if(s.size()==0)
                return false;
            return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
        }
        else{
            return false;
        }
    }
};
int main(){
    Solution s;
    cout<<s.isMatch("aa","a?")<<endl;

}
