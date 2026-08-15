/**
 * Definition for singly-linked list.
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;

        ListNode* a = head;
        ListNode* parent = nullptr;
        ListNode* b = head;

        while(b!=nullptr){
            if(b->val==val && parent!=nullptr){
                parent->next = b->next;
            } 
            else if(b->val==val && parent==nullptr) {
                a = a->next;
            }
            if(b->val!=val) parent = b;
            b = b->next;
        }
        return a;
    }
};