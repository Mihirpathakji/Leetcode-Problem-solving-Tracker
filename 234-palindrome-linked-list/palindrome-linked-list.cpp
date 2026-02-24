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
        //temp points to last element.

        vector<int>final;
        final = original;
        reverse(final.begin(),final.end());//final contains reversed elements.

        return final == original;

        //TC:O(n)
        //SC:O(n)


    }
};