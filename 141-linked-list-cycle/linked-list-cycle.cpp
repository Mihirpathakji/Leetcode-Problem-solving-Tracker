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
        int index = 0;
        if(!temp)
        {
            return false;
        }
        
        unordered_map<ListNode*,int>mp;
        mp[head]++;//mp[1]=1
        int x  =100001;
        while(x--)
        {
            if(temp)
            temp = temp->next;

            if(temp!=NULL && mp.find(temp)!=mp.end())
            {
                return true;
            }
            
            mp[temp]++;
        }

        return false;
        
    }
};