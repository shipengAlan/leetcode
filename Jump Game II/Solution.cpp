#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(curRch < i)//��ǰλ�ó�����ǰ���ܵ������Զλ�ã�ret��¼��Ծ
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, nums[i]+i);//������չ��ǰ���ܵ������Զλ��
        }
        return ret;
    }
};
int main(){
    int a[5] = {2,3,1,1,4};
    vector<int> nums(a,a+5);
    Solution s;
    cout<<s.jump(nums);

}
