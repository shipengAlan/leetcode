#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = generateString(n,n);
        return res;
    }
    vector<string> generateString(int left,int right){
        vector<string> res;
        if(left==right&&left==0){
            res.push_back("");
            return res;
        }
        if(left<right){
            if(left>0){
                vector<string> temp = generateString(left-1,right);
                for(int i=0;i<temp.size();i++)
                    res.push_back("("+temp[i]);
            }

            if(right>0){
                vector<string> temp =  generateString(left,right-1);
                for(int i=0;i<temp.size();i++)
                    res.push_back(")"+temp[i]);
            }
        }
        if(left==right){
            vector<string> temp = generateString(left-1,right);
            for(int i=0;i<temp.size();i++)
                res.push_back("("+temp[i]);
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}
