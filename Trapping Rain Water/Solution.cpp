#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1)
            return 0;
        int max_index = 0;
        int max_num = 0;
        for(int i=0;i<height.size();i++){
            if(height[i]>max_num){
                max_index = i;
                max_num = height[i];
            }
        }
        int sum = 0;
        int current = height[0];
        for(int i=0;i<max_index;i++){
            if(current>height[i])
                sum+=current-height[i];
            else
                current = height[i];
        }
        current = height[height.size()-1];
        for(int i=height.size()-1;i>max_index;i--){
            if(current>height[i])
                sum+=current-height[i];
            else
                current = height[i];
        }
        return sum;
    }

};
int main(){
    Solution s;
    int a[12] ={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> in(a,a+12);
    cout<<s.trap(in)<<endl;
}
