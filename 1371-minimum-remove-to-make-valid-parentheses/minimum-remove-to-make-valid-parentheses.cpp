class Solution {
public:
    string minRemoveToMakeValid(string s) {
       
        //Space Optimized : 

        /*  
                 Intuition : 

            ->Either any left bracket cannot be balanced or right bracket cannot be balanced.
            
            ->Left bracket cannot be balanced only when there does not exists a valid right ")" over the entire string from it's index , so it's index would remain in the stack.

            -> If any right bracket cannot be balanced -> There does not exists any left bracket to balanced it.So stack would be empty for that right bracket.

        */

        int n = s.length();
        stack<int>left_index_to_be_removed;//

        for(int i = 0;i < n;i++) {
            if(s[i] == '(') { 
                left_index_to_be_removed.push(i); // [2 3]
            }
            else if (s[i] == ')') {
                if(!left_index_to_be_removed.empty()) {

                    //for this right there does exists a valid left to get this right balanced.

                    left_index_to_be_removed.pop();
                }
                else {
                    s[i] = 'I';//This ')' cannot be balanced , we need to remove it.Marked it as invalid.
                }
            }
        } 

        while(!left_index_to_be_removed.empty()) {
            //for this left brackets there does not exists any right inorder to balanced out them.

            //they will remain unbalanced.
            s[left_index_to_be_removed.top()] = 'I';//An invalid char which cannot be there in the s.
            left_index_to_be_removed.pop();

        }

        string ans;

        for(auto& character : s) {
            if(character!='I') {
                ans.push_back(character);
            }
        }

        return ans;

        //TC : O(n)
        //SC : O(1)

        
    }
};