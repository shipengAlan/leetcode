#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int s = 1;
        string all_number = "123456789";
        vector<char> number;
        for(int i=1;i<=n;i++){
            s *= i;
            number.push_back(all_number[i-1]);
        }
        string result = "";
        for(int i=n;i>=1;i--){
            s = s/i;
            int a = (k-1)/s;
            result+=number[a];
            number.erase(number.begin()+ a);
            k = k - a*s;
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.getPermutation(3,6);

}
