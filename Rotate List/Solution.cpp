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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL)
            return head;
        ListNode* current = head;
        int n = 0;
        ListNode* last;
        while(current != NULL){
            n++;
            last = current;
            current = current->next;
        }
        current = head;
        k = k % n;
        n -= k;
        if(n==0||k==0)
            return head;
        while(n>1){
            n--;
            current = current->next;
        }
        ListNode* result = current->next;
        current->next = NULL;
        last->next = head;
        return result;
    }
};
int main(){
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode* result = s.rotateRight(&l1, 11);
    while(result != NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
}
