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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      vector<ListNode*> ans;
      int n=0;
      ListNode* temp=head;
      while(temp!=nullptr){
        n++;
        temp=temp->next;
      }
      int t=n/k;
      int x=n%k;
      temp=head;
      for(int i = 0; i < k; i++) {

            ListNode* start = temp;

            int size = t;

            if(x > 0) {
                size++;
                x--;
            }

            if(size == 0) {
                ans.push_back(nullptr);
                continue;
            }

            ListNode* curr = temp;

            for(int j = 1; j < size; j++) {
                curr = curr->next;
            }

            temp = curr->next;
            curr->next = nullptr;

            ans.push_back(start);
        }

      return ans;

    }
};