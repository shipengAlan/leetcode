#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head;
        ListNode * current1 = l1;
        ListNode * current2 = l2;
        ListNode * current = NULL;
        if(current1!=NULL&&current2!=NULL){
            if(current1->val>current2->val){
                ListNode * node = new ListNode(current2->val);
                head = node;
                current = node;
                current2 = current2->next;
            }
            else{
                ListNode * node = new ListNode(current1->val);
                head = node;
                current = node;
                current1 = current1->next;
            }

        }
        else if(current1!=NULL){
            ListNode * node = new ListNode(current1->val);
            head = node;
            current = node;
            current1 = current1->next;
        }
        else if(current2!=NULL){
            ListNode * node = new ListNode(current2->val);
            head = node;
            current = node;
            current2 = current2->next;
        }
        else
            head = NULL;

        while(current1!=NULL||current2!=NULL){
            if(current1==NULL){
                 ListNode * node = new ListNode(current2->val);
                 current->next = node;
                 current = node;
                 current2 = current2->next;
            }
            else if(current2==NULL){
                 ListNode * node = new ListNode(current1->val);
                 current->next = node;
                 current = node;
                 current1 = current1->next;
            }
            else{
                if(current1->val>current2->val){
                    ListNode * node = new ListNode(current2->val);
                    current->next = node;
                    current = node;
                    current2 = current2->next;
                }
                else{
                    ListNode * node = new ListNode(current1->val);
                    current->next = node;
                    current = node;
                    current1 = current1->next;
                }

            }
        }
        return head;
    }
};
