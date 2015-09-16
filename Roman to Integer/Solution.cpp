#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map_capital_num;
        map_capital_num['I'] = 1;
        map_capital_num['V'] = 5;
        map_capital_num['X'] = 10;
        map_capital_num['L'] = 50;
        map_capital_num['C'] = 100;
        map_capital_num['D'] = 500;
        map_capital_num['M'] = 1000;
        int num_temp = 0;
        int sum = 0;
        int num = 0;
        for(int i=0;i<s.size();i++){
            num = map_capital_num[s[i]];
            sum+=num;
            if(num>num_temp){
                sum-=2*num_temp;

            }
            num_temp = num;
        }
        return sum;
    }
};
int main(){
    Solution s;
    cout<<s.romanToInt("MCD");
}
