/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* temp = head;
        if(!temp)
        {
            return false;
        }
        
        unordered_map<ListNode*,bool>mp;

        int x = 10000;

        while(x--)
        {
            if(temp)
            {
                mp[temp] = true;//mp[head]=T
                temp = temp->next;
            }

            if(temp!=NULL && mp.find(temp)!=mp.end())
            {
                return true;
            }

        }

        return false;

        //TC : O(10^4)
        //SC : O(10^4)
        
    }
};