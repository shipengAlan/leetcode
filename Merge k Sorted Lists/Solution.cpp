#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector< ListNode* > & lists) {
        if(lists.size()==0)
            return NULL;
        vector< ListNode* >::iterator it = lists.begin();
        while(lists.size()>1){
            if((it+1)!=lists.end()){
                ListNode* head = mergeTwoLists(*it,*(it+1));
                lists.erase(it);
                lists.erase(it);
                lists.push_back(head);
                if(it==lists.end())
                    it = lists.begin();
            }
            else{
                it = lists.begin();
            }

        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode * n1, ListNode* n2){
        ListNode* current1 = n1;
        ListNode* current2 = n2;
        ListNode* head = NULL;
        ListNode* now = NULL;
        while(current1!=NULL||current2!=NULL){
            if(current1==NULL){
                if(head==NULL)
                    head = current2;
                if(now==NULL)
                        now = current2;
                else
                    now->next = current2;
                break;
            }
            else if(current2==NULL){
                if(head==NULL)
                    head = current1;
                if(now==NULL)
                    now = current1;
                else
                    now->next = current1;
                break;
            }
            else{
                if(current1->val < current2->val){
                    ListNode *item = new ListNode(current1->val);
                    if(head==NULL)
                        head = item;
                    if(now==NULL)
                        now = item;
                    else{
                        now->next = item;
                        now = item;
                    }
                    current1 = current1->next;
                }
                else{

                    ListNode *item = new ListNode(current2->val);
                    if(head==NULL)
                        head = item;
                    if(now==NULL)
                        now = item;
                    else{
                        now->next = item;
                        now = item;
                    }
                    current2 = current2->next;
                }
            }
        }
        return head;
    }
};
int main(){
    vector< ListNode* >lists;
    ListNode n1(1);
    ListNode n2(2);
    n1.next = &n2;
    ListNode n3(0);
    ListNode n4(1);
    n3.next = &n4;
    lists.push_back(&n1);
    lists.push_back(&n3);
    Solution s;
    ListNode * res = s.mergeKLists(lists);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    cout<<res<<endl;

}
