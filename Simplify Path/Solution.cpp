#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i =0;
        while(i<path.size()){
            while(i<path.size()&&path[i]=='/')
                i++;
            string name = "";
            while(i<path.size()&&path[i]!='/'){
                name = name + path[i];
                i++;
            }
            //cout<<"name"<<name<<endl;
            if(name == ".."){
                if(s.size()>0)
                    s.pop();
            }
            else{
                if(name!="."&&name!="")
                    s.push(name);
            }
            //cout<<"top"<<s.top()<<endl;
        }
        string result = "";
        while(s.size()>0){
            string c = s.top();
            result = "/" + c + result;
            s.pop();
        }
        if(result=="")
            result="/";
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.simplifyPath("/...")<<endl;
    cout<<s.simplifyPath("/a/./b/../../c/")<<endl;
    cout<<s.simplifyPath("/../../")<<endl;
    cout<<s.simplifyPath("/home//foo/")<<endl;
}
