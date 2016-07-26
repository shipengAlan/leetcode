#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r;
        int c = 1;
        for(int i=digits.size()-1;i>=0;i--){
            r = (digits[i] + c) % 10;
            c = (digits[i] + 1) / 10;
            digits[i] = r;
            if(c==0)
                break;
        }
        if(c!=0)
            digits.insert(digits.begin(), c);
        for(int i=0;i<digits.size();i++)
            cout<<digits[i];
        cout<<endl;
        return digits;
    }
};
int main(){
    Solution s;
    vector<int> input;
    //input.push_back(0);
    input.push_back(9);
    input.push_back(9);
    input.push_back(8);
    input.push_back(9);
    input.push_back(9);
    input.push_back(9);
    s.plusOne(input);
}
