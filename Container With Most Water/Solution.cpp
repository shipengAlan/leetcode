#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxA = min(height[left], height[right]) * (right-left);
        while(left<right){
            int maxTemp = min(height[left], height[right]) * (right-left);
            maxA = maxTemp > maxA?maxTemp:maxA;
            if(height[left]<height[right])
                left++;
            else
                right--;

        }
        return maxA;
    }
};
int main(){
    Solution s;
    int a[2]={1,1};
    vector<int> height(a,a+2);
    cout<<s.maxArea(height);
}
