#include<iostream>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID, SPACE, SIGN, DOT, E, DIGIT, LEN
        };
        int trans[][LEN] = {
            {-1,  0,  1,  2, -1,  3},
            {-1, -1, -1,  2, -1,  3},
            {-1, -1, -1, -1, -1,  4},
            {-1,  5, -1,  4,  6,  3},
            {-1,  5, -1, -1,  6,  4},
            {-1,  5, -1, -1, -1, -1},
            {-1, -1,  7, -1, -1,  8},
            {-1, -1, -1, -1, -1,  8},
            {-1,  5, -1, -1, -1,  8}
        };
        int state = 0;
        int c = 0;
        while (c<s.size()) {
            InputType input;
            if (s[c]==' ') {
                input = SPACE;
            } else if (s[c] == '+' || s[c] == '-') {
                input = SIGN;
            } else if (s[c] == '.') {
                input = DOT;
            } else if (s[c] == 'e' || s[c] == 'E') {
                input = E;
            } else if (s[c]-'0'>=0&&s[c]-'0'<=9) {
                input = DIGIT;
            } else {
                input = INVALID;
            }
            state = trans[state][input];
            if (state == -1) {
                return false;
            }
            c++;
        }
        return state == 3 || state == 4 || state == 5 || state == 8;
    }
};
int main(){
    Solution s;
    cout<<s.isNumber("0")<<endl;
    cout<<s.isNumber(" 0.1 ")<<endl;
    cout<<s.isNumber("abc")<<endl;
    cout<<s.isNumber("1 a")<<endl;
    cout<<s.isNumber("2e10")<<endl;
    cout<<s.isNumber(". ")<<endl;
}
