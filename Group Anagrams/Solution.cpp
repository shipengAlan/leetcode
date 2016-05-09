#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > result;
        map<string, int> str_index;
        vector<int> index;
        for(int i=0;i<strs.size();i++){
            char* cur_str = new char[strs[i].length()+1];
            cur_str[strs[i].length()] = '\0';
            for(int j=0;j<strs[i].length();j++)
                cur_str[j]=strs[i][j];
            if(strs[i].length()>0){
                for(int j=0;j<strs[i].length()-1;j++){
                    for(int k=j+1;k<strs[i].length();k++){
                        if(cur_str[j]-'a'>cur_str[k]-'a'){
                            char temp = cur_str[j];
                            cur_str[j] = cur_str[k];
                            cur_str[k] = temp;
                        }
                    }
                }
            }
            string s(cur_str);
            delete [] cur_str;
            if(str_index.find(s)!=str_index.end()){
                int id = str_index.find(s)->second;
                int cur_id = 0;
                for(int j=0;j<result[id].size();j++){
                    //compare two string
                    int compare = 0;
                    for(int k=0;k<strs[i].length();k++){
                        if((strs[i][k]-'a')>(result[id][j][k]-'a')){
                            compare = 1;
                            break;
                        }
                        else if((strs[i][k]-'a')<(result[id][j][k]-'a')){
                            compare = -1;
                            break;
                        }
                    }
                    if(compare==1){
                        cur_id++;
                    }
                    if(compare==-1)
                        break;
                }
                if(cur_id==result[id].size())
                    result[id].push_back(strs[i]);
                else
                    result[id].insert(result[id].begin()+cur_id, strs[i]);
            }
            else{
                vector<string> item;
                item.push_back(strs[i]);
                result.push_back(item);
                str_index.insert(pair<string,int>(s,result.size()-1));
            }
        }
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        return result;
    }
};

int main(){
    vector<string> strs;
    //strs.push_back("");
    strs.push_back("and");
    strs.push_back("dan");
    Solution s;
    s.groupAnagrams(strs);
    return 0;
}
