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
    ListNode* reverseList(ListNode* head) {
        // If head points to NULL or head->next is null then return:
        if(head == nullptr || head->next == nullptr) return head;
        // Start with a temp pointer to point at the second node:
        ListNode *firstPtr = head;
        ListNode *secondPtr = head->next;
        ListNode *thirdPtr = secondPtr->next;

        while(secondPtr != nullptr) {
             if(firstPtr == head) firstPtr->next = nullptr;

             secondPtr->next = firstPtr;
             firstPtr = secondPtr;
             secondPtr = thirdPtr;
             if(thirdPtr != nullptr) thirdPtr = thirdPtr->next;
        }
        return firstPtr;
    }
};