#include<iostream>
using namespace std;
class Solution {
public:

    bool isMatch(string s, string p) {
        cout<<s<<"   "<<p<<endl;
        int slength = s.size();
        int plength = p.size();
        if(slength==0&&plength==0)
            return true;
        if(plength==1){
            if(slength==0)
                return false;
            else if(s[0]!=p[0]&&p[0]!='.')
                return false;
            else
                return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
        }
        else{
            if(p[1]=='*')
            {
                if(isMatch(s,p.substr(2,p.size()-2)))
                    return true;
                int i = 0;
                while(i < slength && (s[i] == p[0] || p[0] == '.')){
                    if(isMatch(s.substr(i+1,s.size()-i-1), p.substr(2,p.size()-2))){
                        return true;
                    }
                    i++;
                }
                return false;
            }
            else{
                if(slength==0)
                    return false;
                if(s[0]==p[0]||p[0]=='.')
                    return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
                else
                    return false;
            }
        }
    }
};
int main(){
    Solution s;
    //cout<<s.isMatch("bbbba", ".*a*a");
    cout<<s.isMatch("ab", ".*c");

}
        //cout<<i<<" "<<j<<endl;
/*
struct node * start = new struct node;
        start->out_edge2 = NULL;
        start->next2 = NULL;
        struct node * current = start;
        for(int i=0;i<p.size();i++){
            char c=p[i];
            if(c!='*'){
                struct node *n = new struct node;
                current->out_edge = c;
                current->next = n;
                current->out_edge2 = NULL;
                current->next2 = NULL;
                current = n;
            }
            else{
                struct node *n = new struct node;
                current->out_edge = '.';
                current->next = n;
                current->out_edge2 = NULL;
                current->next2 = NULL;
                //
                current = n;
                current->out_edge = '.';
                struct node *n2 = new struct node;
                current->next = n;
                current = n;
            }
        }
        current->next = NULL;
        current = start;
        int i = 0;
        while(current!=NULL){
            cout<<current->out_edge<<endl;
            current = current->next;
            i++;
        }
        return true;
*/
