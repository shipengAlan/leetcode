#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<char> s;
        int i =0;
        while(i<path.size()){
            cout<<i<<endl;
            if(s.size()>0)
                cout<<"top:"<<s.top()<<",size:"<<s.size()<<endl;
            if(path[i]=='.'){
                if(s.size()>0&&s.top()=='.'){
                    s.pop();
                    if(s.size()>0&&s.top()=='/'){
                        s.pop();
                        while(s.size()>0&&s.top()!='/'){
                            s.pop();
                        }
                        cout<<s.size()<<endl;
                        //if(s.top()=='/')
                        //    s.pop();
                    }
                    else{
                        cout<<"+"<<endl;
                        s.push(path[i]);
                    }
                }
                else{
                    cout<<"++"<<endl;
                    s.push(path[i]);
                }
            }else if(path[i]=='/'){
                if(s.size()>0&&s.top()=='.')
                    s.pop();
                if(s.size()==0||s.top()!='/')
                    s.push(path[i]);

            }
            else{
                if(s.size()>0&&s.top()=='.')
                    s.pop();
                s.push(path[i]);

            }
            i++;
        }
        string result = "";
        if(s.size()>0&&s.top()=='/')
            s.pop();
        //if(s.size()>0&&s.top()=='.')
        //    s.pop();
        while(s.size()>0){
            char c = s.top();
            result = c + result;
            s.pop();
        }
        if(result=="")
            result="/";
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.simplifyPath("/...");
}
