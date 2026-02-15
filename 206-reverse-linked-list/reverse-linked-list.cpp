/**
 * Definition for singly-linked list.
 * class ListNode {
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
        
        vector<int>ans;
        ListNode* temp = head;

        while(temp != NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int index = ans.size() - 1;
        temp = head;

        while(temp != NULL)
        {
            temp->val = ans[index];//5 4 3 2 1
            index--;//3  2  1  0 -1 
            temp = temp->next;//100 200 300 400 NULL
        } 

        return head;

        //TC:O(n)
        //SC:O(n)

    }
};