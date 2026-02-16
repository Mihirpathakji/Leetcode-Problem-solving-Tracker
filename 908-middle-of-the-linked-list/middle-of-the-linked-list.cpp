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

        ListNode* temp = head;
        long long n = 0;
       
        while(temp != NULL)
        {
            temp = temp->next;
            n++;
        }//O(n)
        //n = total number of nodes in the Linkedlist.

        long long mid = n/2;//2 or 3
        temp = head;
        
        while(mid--)
        {
            temp = temp->next;
        }//O(n/2)

        head = temp;
        return head;

        //TC:O(n)
        //SC:O(1)

    }
};