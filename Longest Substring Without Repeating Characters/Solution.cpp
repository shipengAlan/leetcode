#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {//�ƶ�i��ȷ��start��λ�ã�������ִ����ȣ���������Ӵ�����
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
