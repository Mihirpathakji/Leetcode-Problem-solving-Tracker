class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans;

        int counter = 0;
        int n = s.length();

        for(int j = 0;j < n;j++) {

            if(s[j] == '(') {

                if(counter > 0) {
                    ans.push_back(s[j]);
                }
                
                counter++;
            }

            else if(s[j] == ')' ) {

                counter--;
                if(counter > 0) {
                    ans.push_back(s[j]);
                }
        
            }
        }

        return ans;
        
        //TC : O(n)
        //SC : O(1)
        
    }
};