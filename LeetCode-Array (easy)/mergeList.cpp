#include<iostream>

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *prev = nullptr;
        if(!curr1)
            return curr2;
        else if(!curr2)
            return curr1;
        
        while(curr2)
        {
            while(curr1->next)
            {
                if (curr2->val < curr1->val){
                    ListNode *temp = curr2;
                    curr2 = curr2->next;
                    if(!prev) {
                        temp->next = l1;
                        l1 = temp;
                    } else{
                        
                        temp->next = curr1;
                        prev->next = temp;
                        prev = temp;
                        break;
                    }
                } else {
                    prev = curr1;
                    curr1 = curr1->next;
                }
            }
            if(!curr1->next){
                curr1->next = curr2;
                return l1;
            }
        }
        return l1;
    }
};


int main()
{
    

}
