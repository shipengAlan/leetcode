#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        int j = 0;
        ListNode * first = NULL;
        ListNode * current = head;
        ListNode * last = NULL;
        ListNode * before = head;
        ListNode * start = head;
        while(current!=NULL){
            if(j==0){
                first = current;
            }
            if(j==k-1){
                last = current;
                //reverse
                ListNode* now = first;
                ListNode* new_now = last->next;
                ListNode* next_node = last->next;
                while(now!=(next_node)){
                    ListNode* tmp = now;
                    now = now->next;
                    tmp->next = new_now;
                    new_now = tmp;
                }
                if(i==k-1){
                    start = new_now;
                }
                else
                    before->next = new_now;
                j=-1;
                before = first;
                current = first;
            }
            current = current->next;
            i++;
            j++;
        }
        return start;
    }
};
int main(){
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    ListNode* head = s.reverseKGroup(&node1,0);
    while(head!=NULL)
    {
        cout<<head->val<<endl;
        head = head->next;
    }

}
