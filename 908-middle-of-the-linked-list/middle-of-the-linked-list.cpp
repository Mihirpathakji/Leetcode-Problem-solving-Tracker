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
        
        long long n = 0;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }//O(n)

        long long mid = 0;
        if(n % 2 == 0)
        {
            mid = (n/2)+1;  
        }   
        else
        {
            mid = ceil((float)n/2);
        }

        long long  cnt =1;
        
        temp = head;
        
        while(cnt != mid)
        {
            temp = temp->next;
            cnt++;
        }//O(n/2)

        head = temp;
        return head;

    //TC:O(n)
    //SC:O(1)

    }
};