#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result=NULL;
        ListNode* result_current=NULL;
        ListNode* current=NULL;
        if(head==NULL)
            return result;
        else{
            current = head;
            while(current!=NULL){
                ListNode* next=current->next;
                while(next!=NULL&&next->val==current->val){
                    next = next->next;
                }
                if(result==NULL){
                    result = new ListNode(current->val);
                    result_current = result;
                }
                else{
                    result_current->next = new ListNode(current->val);
                    result_current = result_current->next;
                }
                current = next;
            }
            return result;
        }
    }
};
int main(){
    Solution s;
    //1->1->1->2->3
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    int a[7] = {1,2,3,3,4,4,5};
    for(int i=1;i<7;i++){
        ListNode* t = new ListNode(a[i]);
        current->next = t;
        current = current->next;
    }
    current->next = NULL;
    current = head;
    while(current!=NULL){
        cout<<current->val<<endl;
        current = current->next;
    }
    cout<<"output"<<endl;
    ListNode* result = s.deleteDuplicates(head);
    current = result;
    while(current!=NULL){
        cout<<current->val<<endl;
        current = current->next;
    }
}
