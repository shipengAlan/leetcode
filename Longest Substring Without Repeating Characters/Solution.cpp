#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {//移动i，确定start的位置，计算机字串长度，更新最大子串长度
        if(s.empty())
            return 0;
        int charlist[256];
        memset(charlist,-1,sizeof(charlist));
        int p_start = -1;
        int max = 0;
        for(int i=0;i<s.length();i++){
            if(charlist[s[i]] > p_start){
                p_start=charlist[s[i]];

            }
            max = (max < (i-p_start))?(i-p_start):max;
            charlist[s[i]] = i;
        }
        return max;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb");

}
