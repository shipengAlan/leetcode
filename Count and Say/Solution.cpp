#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)
            return "";
        string str = "1";
        for(int i=1;i<n;i++){
            str = convertNext(str);
        }
        return str;
    }
    string convertNext(string str){
        stringstream ss;
        char last = str[0];
        int count = 0;
        for(int j=0;j<=str.size();j++){//string 最后一个字符
            char current = str[j];
            if(last!=current){
                ss << count << last;
                count = 1;
            }
            else{
                count++;
            }
            last = current;
        }

        return ss.str();
    }
};
int main(){
    Solution s;
    cout<<s.countAndSay(5);
}
