#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1||numRows==1)
            return s;
        string str = "";
        for(int i=0;i<numRows;i++){
            int first = i;
            int step = (numRows-1)*2;
            int index = first;
            int index2= (numRows-i-1)*2+i;
            if(i==0||i==numRows-1)
                index2 = first;
                while(index<s.size()&&index2<s.size()){
                    cout<<index<<","<<index2<<endl;
                    if(index==index2)
                        str += s[index];
                    else{
                        if(index<s.size())
                            str += s[index];
                        if(index2<s.size())
                            str += s[index2];
                    }
                    index+=step;
                    index2+=step;
                }
                if(index<s.size())
                    while(index<s.size()){
                        str += s[index];
                        index+=step;
                    }
                if(index2<s.size())
                    while(index2<s.size()){
                        str += s[index2];
                        index2+=step;
                    }
                cout<<"---------"<<endl;
        }
        return str;

    }
};
int main(){
    Solution s;
    cout<<s.convert("A",1)<<endl;
}
