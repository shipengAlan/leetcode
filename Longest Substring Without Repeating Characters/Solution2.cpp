#include<iostream>
#include<string.h>
#include<set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {//移动i，确定start的位置，计算机字串长度，更新最大子串长度
        int max = 0;
        int left = 0;
        int right = 0;
        set<int> set_int;
        while(right<s.length()){
            if(set_int.find(s[right])!=set_int.end()){
                while(s[left]!=s[right]){
                    set_int.erase(s[left]);
                    left++;
               }
               left++;
            }
            else{
                set_int.insert(s[right]);
                max = (max>set_int.size())?max:set_int.size();
            }
            right++;
        }
        return max;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
}

