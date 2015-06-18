#include<iostream>
#include <stdlib.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* next_l1 = l1;
        ListNode* next_l2 = l2;
        ListNode* result=NULL;
        ListNode* current=NULL;
        int addnext = 0;
        while( next_l1 != NULL && next_l2 != NULL )
        {
            int temp = next_l1->val + next_l2->val + addnext;
            addnext = temp / 10;
            ListNode* node = new ListNode(temp%10);
            //ListNode* node = (ListNode* )malloc(sizeof(struct ListNode));
            //node->val = temp%10;
            if(result!=NULL)
            {
                current->next = node;
                current = node;
            }
            else
            {
                result = node;
                current = node;
            }
            next_l1 = next_l1->next;
            next_l2 = next_l2->next;
        }
        while(next_l1 != NULL)
        {
            int temp = next_l1->val + addnext;
            addnext = temp / 10;
            ListNode* node = new ListNode(temp%10);
            if(current!=NULL)
            {
                current->next = node;
            }
            else
            {
                result = node;
            }
            current = node;
            next_l1 = next_l1->next;
        }
        while(next_l2 != NULL)
        {
            int temp = next_l2->val + addnext;
            addnext = temp / 10;
            ListNode* node = new ListNode(temp%10);
            if(current!=NULL)
            {
                current->next = node;
            }
            else
            {
                result = node;
            }
            current = node;
            next_l2 = next_l2->next;
        }
        if(addnext>0)
        {
            ListNode* node = new ListNode(addnext%10);
            current->next = node;
        }

        return result;
    }
};
int main()
{
    struct ListNode add11(2);
    struct ListNode add12(4);
    struct ListNode add13(3);
    add11.next = &add12;
    add12.next = &add13;

    struct ListNode add21(5);
    struct ListNode add22(6);
    struct ListNode add23(4);
    add21.next = &add22;
    add22.next = &add23;
    Solution s;
    ListNode* node=s.addTwoNumbers(&add11,&add21);
    ListNode* ptr = node;
    cout<<"------------"<<endl;
    int i = 0;
    while(i<3)
    {
        cout<< ptr->val<<endl;
        ptr = ptr->next;
        i++;
    }
    return 0;

}
