#include<iostream>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
ListNode* current = head;
        ListNode* current2 = NULL;
        if(current!=NULL)
         current2 = current->next;
        else
            return head;
        if(current2 ==NULL)
            return head;
        head = current2;
        ListNode* last=NULL;
        while(current!=NULL&&current2!=NULL){
            if(last!=NULL)
                last->next = current2;
            ListNode * temp;
            temp = current2->next;
            current2->next = current;
            current->next = temp;
            last = current;
            current = current->next;
            if(current!=NULL)
                current2 = current->next;
            else
                break;
        }
        return head;
    }
};
