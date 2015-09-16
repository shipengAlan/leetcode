#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string z[7] = {"I","V","X","L","C","D","M"};
        int n[7] = {1,5,10,50,100,500,1000};
        string res;
        int shang = 0;
        int i = 6;
        while(num!=0&&i>=0){
            shang = num/n[i];
            num = num%n[i];
            //cout<<shang<<num;
            if(shang!=0){
                if(shang==4){
                    res = res + z[i] + z[i+1];
                }
                else if(shang==9){
                    res = res + z[i] + z[i+2] ;
                }
                else if(shang<4){
                    for(int j=0;j<shang;j++){
                        res = res + z[i];
                    }
                }
                else{
                    res = res + z[i+1];
                    for(int j=0;j<shang-5;j++){
                        res = res + z[i];
                    }
                }

            }
            i-=2;
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.intToRoman(1899);
}
