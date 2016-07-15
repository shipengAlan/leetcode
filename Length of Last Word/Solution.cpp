#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        if(s.length()==0)
            return result;
        else{
            int start = 0;
            int i=s.length()-1;
            for(;i>=0,s[i]==' ';i--);
            for(;i>=0;i--){
                if(s[i]!=' ')
                    result ++;
                else
                    break;
            }
            return result;
        }
    }
};
int main(){
    Solution s;
    int result = s.lengthOfLastWord(" a   ");
    cout<<result<<endl;
}
