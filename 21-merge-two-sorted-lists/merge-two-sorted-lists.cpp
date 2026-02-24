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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* curr = nullptr;
        ListNode* temp = nullptr;

        ListNode* Prev1 = list1;//0
        ListNode* Prev2 = list2;//nullptr

        if(Prev1 == NULL && Prev2 != NULL)
        {
            temp = Prev2;
            return temp;
        }
        else if(Prev2 == NULL  && Prev1 != NULL)
        {
            temp = Prev1;
            return temp;
        }

    while(Prev1!= NULL && Prev2 !=NULL)
    {//Prev1 = 2;
        if(Prev1->val <= Prev2->val)
        {   
            if(temp == NULL)
            temp = Prev1;//1
            
            if(curr != NULL)
            curr->next =Prev1;
            
            curr = Prev1;//1
            Prev1 = Prev1->next;//2
        }
        else
        {   
            if(temp == NULL)
            temp = Prev2;//1

            if(curr!=NULL)
            curr->next = Prev2;
            
            curr = Prev2;
            Prev2 = Prev2->next;
        }
    }
    
    if(Prev1 == NULL)
    {
        if(curr != NULL)
        curr->next = Prev2;
    }
    else
    {
        if(curr != NULL)
        curr->next = Prev1;
    }

    return temp;

    //TC:O(n+m)
    //SC:O(1)

    }
};