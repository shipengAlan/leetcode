#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<string> result;
        while(i<words.size()){
            int j = i;
            int length = 0;
            while(length-1<=maxWidth&&j<words.size()){
                length += words[j].length() + 1;
                j++;
            }
            //cout<<length<<endl;
            if(length-1>maxWidth){
                length -= words[j-1].length() + 1 + 1;
                j = j - 1;
            }
            else{
                length -= 1;
            }
            //cout<<length<<endl;
            //cout<<j<<endl;
            if(j==(words.size())){
                int k = i;
                string str = "";
                int more_space = maxWidth - length;
                //cout<<"last"<<more_space<<endl;
                str += words[k];
                while(k<j-1){
                    str += " ";
                    k++;
                    str += words[k];
                }
                while(1){
                    if(more_space>0)
                        str += " ";
                    else
                        break;
                    more_space --;
                }
                cout<<str<<endl;
                result.push_back(str);
            }
            else{
                int space = maxWidth - length;
                int avg_space = 1;
                int more_space = 0;
                //cout<<space<<endl;
                if(space!=0){
                    if((j - i - 1)==0){
                        avg_space = 0;
                        more_space = space;
                    }
                    else{
                        avg_space = space / (j - i - 1) + 1;
                        more_space = space % (j - i - 1);
                    }

                }
                //cout<<avg_space<<endl;
                //cout<<more_space<<endl;
                int k = i;
                string str = "";
                str += words[k];
                while(k<j-1){
                    for(int e=0;e<avg_space;e++)
                        str += " ";
                    if(more_space>0)
                        str += " ";
                    more_space --;
                    k++;
                    str += words[k];
                    //cout<<"k"<<k<<endl;
                }
                while(1){
                    if(more_space>0)
                        str += " ";
                    else
                        break;
                    more_space --;
                }
                cout<<str<<endl;
                result.push_back(str);
            }
            i = j;
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<string> words;
    //["This", "is", "an", "example", "of", "text", "justification."]
    /*
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification.");
    */
    //["Listen","to","many,","speak","to","a","few."]
    /*
    words.push_back("Listen");
    words.push_back("to");
    words.push_back("many,");
    words.push_back("speak");
    words.push_back("to");
    words.push_back("a");
    words.push_back("few.");*/
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("e");
    //words.push_back("a");
    s.fullJustify(words, 3);
}
