class Solution {
public:
    string minRemoveToMakeValid(string s) {
       
        //Space Optimized : 

        int n = s.length();
        stack<int>left_index_to_be_removed;

        for(int i = 0;i < n;i++) {
            if(s[i] == '(') {
                left_index_to_be_removed.push(i);
            }
            else if (s[i] == ')') {
                if(!left_index_to_be_removed.empty()) {

                    //for this right there does exists a valid left to get this right balanced.

                    left_index_to_be_removed.pop();
                }
                else {
                    s[i] = 'I';
                }
            }
        } 

        while(!left_index_to_be_removed.empty()) {
            //for this left brackets there does not exists any right inorder to balanced out them.

            //they will remain unbalanced.
            s[left_index_to_be_removed.top()] = 'I';
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