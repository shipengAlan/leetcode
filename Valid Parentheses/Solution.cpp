#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stack_str.push(s[i]);
            }
            else{
                if(stack_str.size()==0)
                    return false;
                char c = stack_str.top();
                stack_str.pop();
                if(!((c=='['&&s[i]==']')||(c=='{'&&s[i]=='}')||(c=='('&&s[i]==')')))
                    return false;
            }
        }
        if(stack_str.size()==0)
            return true;
        else
            return false;
    }
};
int main(){
    Solution s;
    cout<<s.isValid("([)]");
}
