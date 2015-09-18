#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowValid[9] = {0};
        int colValid[9] = {0};
        int blockValid[9] = {0};
        int temp = 0;
        for(int i=0;i<9;i++){
            memset(rowValid, 0, sizeof(rowValid));
            memset(colValid, 0, sizeof(colValid));
            memset(blockValid, 0, sizeof(blockValid));

            int count = 0;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValidItem(rowValid,board[i][j]-'1')){
                        return false;
                    }
                }
                if(board[j][i]!='.'){
                    if(!isValidItem(colValid,board[j][i]-'1')){
                        return false;
                    }
                }
                cout<<temp<<" "<<(i/3)*3+j%3<<endl;
                if(board[temp][(i/3)*3+j%3]!='.'){
                    if(!isValidItem(blockValid,board[temp][(i/3)*3+j%3]-'1'))
                        return false;
                }
                count++;
                if(count==3){
                    count=0;
                    temp++;
                }
                if(temp==9)
                    temp=0;

            }
        }
        return true;
    }
    bool isValidItem(int a[],int i){
        if(a[i]==1)
            return false;
        a[i] = 1;
        return true;
    }
};

