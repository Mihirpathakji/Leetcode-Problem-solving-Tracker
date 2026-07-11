class Solution {
public:
    string removeOuterParentheses(string s) {

        //Most Optimal solution : O(1) Auxilliary space.
        //Aim : Remove the Outermost Parnetheses for every valid primtive string.

        string ans;

        int counter = 0;
        int n = s.length();

        for(int j = 0;j < n;j++) {

            if(s[j] == '(') {

                //Only add if it is not outer Parentheses.
               
                if(counter == 0) {
                    //Not already Nested.So now nested it.
                    counter++;    
                }    
                else {
                    ans.push_back(s[j]);
                    counter++;
                }

            }
            else if(s[j] == ')' ) {

                //Add Only if it is already nested by '('
                if(counter > 0) {
                    ans.push_back(s[j]);
                    counter--;//1.//0
                }
                if(counter == 0) {
                    ans.pop_back();
                }
            }
        }

        return ans;
        
        //TC : O(n)
        //SC : O(1)

        
    }
};