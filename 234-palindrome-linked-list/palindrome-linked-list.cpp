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

ListNode* Reverse_Linkedlist(ListNode* Head_Pointer)
{
    ListNode* Prev = NULL;
    ListNode* curr = Head_Pointer;
    ListNode* future = NULL;

    while(curr)
    {
        future = curr->next;
        curr->next = Prev;

        Prev = curr;
        curr = future;
    }

    return Prev;
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {

        //Find the middle node:

        ListNode* temp = head;
        int no_nodes = 0;
        
        while(temp != NULL)
        {
            no_nodes++;
            temp = temp->next;
        }
        
        int middle_node_cnt = no_nodes/2; //4/2 == 2
        
        temp = head;

        while(middle_node_cnt)
        {
            temp = temp->next;
            middle_node_cnt--;//1 0 
        }

        //temp is at the head of the Linkedlist to be Reversed.

        ListNode* PREV = Reverse_Linkedlist(temp);//100
        temp = head;
        
        while(PREV != NULL )
        {
            if(PREV->val != temp->val)
            return false;

            PREV = PREV->next;
            temp = temp->next;
        }
        return true;

    }
};