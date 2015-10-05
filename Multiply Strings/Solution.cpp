#include<iostream>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if(num1.size()<num2.size()){
            for(int i=num1.size()-1;i>=0;i--){
                string temp = multiply_single(num2,num1[i]);
                for(int j=i;j<num1.size()-1;j++)
                    temp = temp + '0';
                res=add(temp,res);
            }
        }
        else{
            for(int i=num2.size()-1;i>=0;i--){
                string temp = multiply_single(num1,num2[i]);
                for(int j=i;j<num2.size()-1;j++)
                    temp = temp + '0';
                res=add(temp,res);
            }
        }
        return res;
    }
    string multiply_single(string num1, char num2){
        string res;
        int c = 0;
        for(int i=num1.size()-1;i>=0;i--){
            int temp = (num1[i]-'0')*(num2-'0');
            res = (char)((temp+c)%10+'0')+res;
            c = (temp+c)/10;
        }
        if(c!=0)
            res = (char)(c+'0')+res;
        return res;

    }
    string add(string num1, string num2) {
        string res;
        int c = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i>=0||j>=0){
            if(i>=0&&j>=0){
                int a = num1[i]-'0';
                int b = num2[j]-'0';
                res = (char)((a+b+c)%10+'0') + res;
                c = (a+b+c)/10;
                i--;
                j--;
            }
            else if(i>=0){
                res = (char)((num1[i]-'0'+c)%10+'0') + res;
                c = (num1[i]-'0'+c)/10;
                i--;
            }
            else if(j>=0){
                res = (char)((num2[j]-'0'+c)%10+'0') + res;
                c = (num2[j]-'0'+c)/10;
                j--;
            }
        }
        if(c!=0)
            while(c!=0){
                res = (char)(c%10+'0')+res;
                c = c/10;
            }

        int k = -1;
        for(int i=0;i<res.size();i++)
            if(res[i]=='0')
                k = i;
            else
                break;
        if(k!=-1){
            if(k==res.size()-1)
                res = "0";
            else{
                res = res.substr(k+1,res.size()-k-1);
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.add("000","000")<<endl;
    cout<<s.multiply("140","721")<<endl;
}
