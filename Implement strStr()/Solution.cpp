#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size_m = haystack.size();
        int size_n = needle.size();
        for(int i=0;i<=(size_m-size_n);i++){
            int j;
            for(j=0;j<size_n;j++){
                if(haystack[i+j]!=needle[j])
                    break;

            }
            if(j==size_n)
                return i;
        }
        return -1;
    }
};
int main(){
    Solution s;
    cout<<s.strStr("abs","sb");

}
