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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode d(0,head);
        ListNode* p=&d;
        ListNode* c=head;
        while(c!=nullptr){
            if(c->next!=nullptr && c->val==c->next->val){
                while(c->next!=nullptr && c->val==c->next->val){
                    c=c->next;
                }
                p->next= c->next;
            }
            else{
                p=p->next;
            }
            c=c->next;
        }
        return d.next;
    }
};