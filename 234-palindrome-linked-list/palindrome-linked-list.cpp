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

    while(curr != NULL)
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
        
        int middle_node_cnt = no_nodes/2;

        temp = head;
        ListNode* dummy = NULL;

        while(middle_node_cnt)
        {
            if(middle_node_cnt == 1)
            {
                dummy = temp;
                temp = temp->next;
                dummy->next = NULL;
                break;
            }
            
            else
            {
                temp = temp->next;
                middle_node_cnt--;
            }
        }

        ListNode* PREV = Reverse_Linkedlist(temp);
        temp = head;
        
        while(PREV != NULL && temp!= NULL )
        {
            if(PREV->val != temp->val)
            return false;

            PREV = PREV->next;
            temp = temp->next;//temp -> pointing to linkedlist with only 2 i.e Lesser number of  Nodes then the prev pointing to linkedlist with 3 Nodes.
        }

        return true;

        //TC:O(n)
        //SC:O(1)

    }
};