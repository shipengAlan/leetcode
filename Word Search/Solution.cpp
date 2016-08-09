#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        char ** state = new char * [board.size()];
        for(int i=0;i<board.size();i++){
            state[i] = new char[board[i].size()];
            memset(state[i], 0, sizeof(char)*board[i].size());
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    state[i][j] = 1;
                    if(search(state, board, word, 1,i,j))
                        return true;
                    state[i][j] = 0;
                }
            }
        }
        return false;

    }
    bool search(char ** state, vector< vector<char> >& board, string word, int w, int r, int c){
        if(w>=word.size())
            return true;
        if(r+1<board.size()&&c<board[0].size()&&w<word.size()){//right{
            if(board[r+1][c]==word[w]&&state[r+1][c]==0){
                state[r+1][c] = 1;
                if(search(state, board, word, w+1,r+1,c)){
                    return true;
                }
                state[r+1][c] = 0;
            }
        }
        if(r-1>=0&&c<board[0].size()&&w<word.size()){//left{
            if(board[r-1][c]==word[w]&&state[r-1][c]==0){
                state[r-1][c] = 1;
                if(search(state, board, word, w+1,r-1,c)){
                    return true;
                }
                state[r-1][c] = 0;
            }
        }
        if(r<board.size()&&c+1<board[0].size()&&w<word.size()){//up
            if(board[r][c+1]==word[w]&&state[r][c+1]==0){
                state[r][c+1] = 1;
                if(search(state, board, word, w+1,r,c+1)){
                    return true;
                }
                state[r][c+1] = 0;
            }
        }
        if(r<board.size()&&c-1>=0&&w<word.size()){//down
            if(board[r][c-1]==word[w]&&state[r][c-1]==0){
                state[r][c-1] = 1;
                if(search(state, board, word, w+1,r,c-1)){
                    return true;
                }
                state[r][c-1] = 0;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector< vector<char> > board;
    char a[4] = {'A','B','C','E'};
    char b[4] = {'S','F','C','S'};
    char c[4] = {'A','D','E','E'};
    vector<char> b1(a, a+4);
    vector<char> b2(b, b+4);
    vector<char> b3(c, c+4);
    board.push_back(b1);
    board.push_back(b2);
    board.push_back(b3);
    string word = "ABCCED";
    cout<<s.exist(board, word);
}
