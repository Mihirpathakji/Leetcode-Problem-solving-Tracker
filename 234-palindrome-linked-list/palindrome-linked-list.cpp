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
    bool isPalindrome(ListNode* head) {

        ListNode* temp = head;
        vector<int>original;
        
        if(temp->next == NULL)
        {
            return true;
        }

        while(temp != NULL)
        {
            original.push_back(temp->val);//1 2
            temp = temp->next;//2
        }
    
        //original[]=[1 2 2 1]
        int l = 0;
        int r = original.size() - 1;
        
        while(l < r)
        {
            if(original[l] != original[r])
            {
                return false;
            }
            l++;
            r--;
            
        }

        return true;


        //TC:O(n)
        //SC:O(n)

    }
};