#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int p = 0;
        string res;
        char c;
        char last;
        while(1){
            if(strs.size()>0&&(strs[0].size()>p))
                last = strs[0][p];
            else
                return res;
            for(int i=0;i<strs.size();i++){
                string s = strs[i];
                if(p>=s.size())
                    return res;
                c = s[p];
                if(c!=last)
                    return res;

                last = s[p];
            }
            res = res + last;
            p++;
        }
    }
};
int main(){
    Solution s;
    vector<string> sv;
    sv.push_back("ass");
    sv.push_back("asv");
    cout<<s.longestCommonPrefix(sv);
}
