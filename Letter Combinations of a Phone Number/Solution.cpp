#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int label[8] = {3,3,3,3,3,4,3,4};
        int start[8] = {0,3,6,9,12,15,19,22};
        if(digits.size()==0)
            return res;
        for(int j=0;j<label[digits[0]-'2'];j++){
                string str;
                str+=(char)('a'+start[digits[0]-'2']+j);
                res.push_back(str);
        }
        for(int i=1;i<digits.size();i++){
            if(digits[i]-'2'>=0){
                vector<string> temp;
                for(int j=0;j<label[digits[i]-'2'];j++){

                    for(int k=0;k<res.size();k++){
                        string str;
                        str+=res[k] + (char)('a'+start[digits[i]-'2']+j);
                        temp.push_back(str);
                    }

                }
                res.clear();
                for(int k=0;k<temp.size();k++){
                    res.push_back(temp[k]);
                }
                temp.clear();
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<string> res;
    string str ="23";
    res = s.letterCombinations(str);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

}
