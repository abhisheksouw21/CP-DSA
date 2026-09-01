/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(!head || left==right) return head;
        ListNode* temp = new ListNode(0);
        temp->next=head;
        ListNode* p=temp;
        for(int i=0;i<left-1;++i){
            p=p->next;
        }
        ListNode* c= p->next;
        for(int i=0;i<right-left;++i){
            ListNode* t=c->next;
            c->next = t->next;
            t->next=p->next;
            p->next=t;
        }
        ListNode* ans= temp->next;
        delete temp;
        return ans;
    }
};