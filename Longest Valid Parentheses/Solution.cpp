#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        int * idx = new int[length];
        for(int i=length-1;i>=0;i--){
            if(s[i]=='('){
                if(i+1<length){
                    if(s[i+1]==')'){
                        idx[i]=i+1;
                        if(i+2<length)
                            if(idx[i+2]>=0)
                                idx[i]=idx[i+2];
                    }
                    else{
                        int right = idx[i+1];
                        if(right==-1)
                            idx[i]=-1;
                        else{
                            if(idx[i+1]+1<length){
                                if(s[idx[i+1]+1]==')'){
                                    idx[i]=idx[i+1]+1;
                                    if(idx[i+1]+2<length)
                                        if(idx[idx[i+1]+2]>=0)
                                            idx[i]=idx[idx[i+1]+2];
                                }
                                else
                                    idx[i]=-1;
                            }
                            else
                                idx[i]=-1;
                        }
                    }
               }
               else{
                    idx[i] = -1;
               }
            }
            else{
                idx[i] = -1;
            }
        }
        int longest=0;
        for(int i=0;i<length;i++){
            if(idx[i]>=0)
                if(longest<(idx[i]-i+1))
                    longest = (idx[i]-i+1);
        }
        return longest;
    }

};
int main(){
    Solution s;
    cout<<s.longestValidParentheses("((()))())");

}
/*
µÝ¹é»á³¬Ê±
int longestValidParentheses(string s) {
        int l=0;
            while(l<s.size()){
                if(s[l]=='(')
                    break;
                else
                    l++;
            }
            int r=s.size()-1;
            while(r>=0){
                if(s[r]==')')
                    break;
                else
                    r--;
            }
        return isValidSubStr(s,l,r);
    }
    int isValidSubStr(string s,int left,int right){
        if(left>=right)
            return 0;
        if(left+1==right&&s[left]=='('&&s[right]==')')
            return 2;
        stack<char> st;
        int state = 0;
        for(int i=left;i<=right;i++){
            if(s[i]=='(')
                st.push('(');
            else{
                if(st.size()==0){
                    state = 1;
                    break;
                }
                char top = st.top();
                if(top=='(')
                    st.pop();

            }
        }
        if(st.size()==0&&state==0)
            return right-left+1;
        else{
            int l=left+1;
            while(l<right){
                if(s[l]=='(')
                    break;
                else
                    l++;
            }
            int r=right-1;
            while(r>left){
                if(s[r]==')')
                    break;
                else
                    r--;
            }
            int tl = isValidSubStr(s,l,right);
            int tr = isValidSubStr(s,left,r);
            return max(tl,tr);
        }
    }
*/
/*
error
stack<int> st;
        int current=0;
        int best = 0;
        int temp = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push('(');
            else{
                if(st.size()>0){
                    char top = st.top();
                    if(top=='('){
                        if(st.size()==1){
                            current+=2;
                            current+=temp;
                            temp=0;
                            if(best<current)
                                best = current;
                        }
                        else{
                            temp+=2;
                        }
                        st.pop();
                    }
                    else{
                        if(best<current)
                            best = current;
                        current=0;
                        temp=0;
                    }
                }
                else{
                    if(best<current)
                        best = current;
                    current=0;
                    temp=0;
                }
            }
            cout<<current<<" "<<temp<<endl;
        }
        if(st.size()!=0)
            if(temp>current)
                current=temp;
        if(best<current)
            best = current;
        return best;
*/
