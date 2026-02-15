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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Future;

        while(curr != NULL)
        {
            Future = curr->next;//1.Future is first updated.
            curr->next = prev;
            prev = curr;      
            curr = Future;      
        }
        
        //prev contains head of resultant Linkedlist.Futur,curr = NULL
        head = prev;
        return head;
        //TC: O(n)
        //SC:O(1)

    }
};