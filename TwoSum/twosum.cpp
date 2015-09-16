#include<map>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
	    vector<int> temp;
	    vector<int> result;
	    for(int i=0;i<numbers.size();i++)
            temp.push_back(numbers[i]);
        sort(temp.begin(),temp.end());
        int p_start = 0;
        int p_end = temp.size()-1;
        int a,b,sum;
        while(true){
            int sum = temp[p_start]+temp[p_end];
            if(sum==target){
                a = temp[p_start];
                b = temp[p_end];
                break;
            }
            else if (sum<target){
                p_start ++;
            }
            else if(sum>target){
                p_end --;
            }
            if(p_end<0||p_start>=temp.size())
                break;
        }

        for(int i=0;numbers.size();i++)
            if(numbers[i]==a){
                a = i;
                break;
            }
        for(int i=0;numbers.size();i++)
            if(numbers[i]==b&&i!=a){
                b = i;
                break;
            }
        if(a<b){
            result.push_back(a+1);
            result.push_back(b+1);
        }
        else{
            result.push_back(b+1);
            result.push_back(a+1);
        }
        return result;
	}
};
int main(){
	Solution s;
	vector<int> v_input;
	/*
	v_input.push_back(0);
	v_input.push_back(4);
	v_input.push_back(3);
	v_input.push_back(0);
	*/
	/*
    v_input.push_back(3);
	v_input.push_back(2);
	v_input.push_back(4);
	*/
    v_input.push_back(-1);
	v_input.push_back(-2);
	v_input.push_back(-3);
	v_input.push_back(-4);
	v_input.push_back(-5);
    //324 6
    //0430 0
	vector<int> v_result= s.twoSum(v_input, -8);
	vector<int>::iterator it;
    for(it=v_result.begin();it!=v_result.end();it++)
    cout<<*it<<endl;
	return 0;
}
/*
        vector<int> result;
		map<int,int> map_numbers;
		map<int,int>::iterator l_it;
		for(int i=0;i<numbers.size();i++){
		    l_it = map_numbers.find(numbers[i]);
            if(l_it!=map_numbers.end()){
                vector<int> v;
                v.push_back(i);
                map_numbers.insert(pair<int,vector<int>>(numbers[i],v));
            }
            else{
                l_it->second->insert(i);
            }

		}
        for(int i=0;i<numbers.size();i++){
            l_it = map_numbers.find(target-numbers[i]);
            if(l_it!=map_numbers.end()){
                if(l_it->second>i){
                    result.push_back(i+1);
                    result.push_back(l_it->second+1);
                    break;
                }else if(l_it->second==i){

                }
            }
		}
        return result;

*/
