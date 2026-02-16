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
    ListNode* middleNode(ListNode* head) {

        //Optimized Approach using Slow and Fast Pointers :
        ListNode* slow  = head;
        ListNode* fast  = head;

        while( fast != NULL && fast->next != NULL)
        {
            slow  = slow->next;//Move ahead by 1 step.
            fast  = fast->next->next;//Move the fast pointer by 2 steps. 
        }//O(n)
       
        //In this way slow pointer will be pointing to the mid
        return slow;

        //TC:O(n)
        //SC:O(1)

    }
};