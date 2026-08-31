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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
     // store critical points in a vector and then find the max and min   
     vector<int>v;
     ListNode* p=head;
     ListNode* c=head->next;
     int idx=1;
     while(c!=nullptr && c->next!=nullptr){
        if((c->val > p->val && c->val > c->next->val) || (c->val < p->val && c->val < c->next->val)){
            v.push_back(idx);
        }
        p=c;
        c=c->next;
        idx++;
             }
             if(v.size()<2){
                return {-1,-1};
                             }
    int mn=INT_MAX;
    int mx=v.back()-v.front();
    for(int i=1; i<v.size();++i){
        mn=min(mn,v[i]-v[i-1]);
    }
    return {mn,mx};
    }
};