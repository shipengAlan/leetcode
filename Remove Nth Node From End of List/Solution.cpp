#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)
            return head;
        int size = 0;
        ListNode * current = head;
        while(current!=NULL){
            cout<<size<<endl;
            size++;
            current = current->next;
        }
        int count = 0;
        current = head;
        while(count<size-n-1){
            count++;
            current = current->next;
        }
        if(n==size)
            head = current->next;
        else
            current->next = current->next->next;
        return head;
    }
};

int main(){
    Solution s;
    s.removeNthFromEnd(NULL,0);
}
