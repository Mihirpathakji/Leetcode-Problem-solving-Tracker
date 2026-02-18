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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        long long no_nodes = 0;
        ListNode* temp = head;

        //Count Present Number of nodes in the Linkedlist.
        while(temp != NULL)
        {
            no_nodes++;//1  2 
            temp = temp->next;//2 null
        }//O(n)

        //Find out the Node number from begining since in the linkedlist traversal from end in backward direction is not possible.
        
        long long x = (no_nodes - n + 1);//(3-3+1)==1 
        long long cnt = 1;//1

        temp = head->next;//2
        ListNode* curr = head;//1

        if(no_nodes == 1)
        {
            return nullptr;
        }
        //Very big edge case:Since in our code cnt has starting value == 1.cnt == 1-1 == 0 will never happen for all x == 1.Hence Handle edge case x == 1.Since it is not covered below.

        //cnt == 1-1 will be never true
        
        if(x == 1)
        {  
            curr->next = NULL;
            delete curr;   
            head = temp;
            return head;
        }
        

        while(temp != NULL)
        {
            //first check condition:
            if(cnt == x - 1)
            {
                curr->next = temp->next;
                delete temp;
                break;
            }
            if(cnt ==  x)
            {
                break;
            }

            curr = temp;//2
            temp = temp->next; //null
            cnt++;//2 
        }//O(n)
        
        return head;

        //TC:O(n)
        //SC:O(1)

    }
};