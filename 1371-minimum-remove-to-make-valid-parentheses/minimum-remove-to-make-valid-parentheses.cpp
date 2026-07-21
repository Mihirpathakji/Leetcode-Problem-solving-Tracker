class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();

        vector<int>left_bracket_index(n,0);
        vector<int>right_bracket_index(n,0);

        for(int i = 0;i < n;i++) {
            if(s[i] == '(') {
                left_bracket_index[i] = 1;
            }
            else if(s[i] == ')') {
                right_bracket_index[i] = 1;
            }
        }

        stack<int>st;
        //Insert only the "left opening" bracket's index.

        for(int i = 0;i < n;i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()) {
                    left_bracket_index[st.top()] = 0;
                    right_bracket_index[i] = 0;
                    st.pop();
                }
            }
        }

        string ans;
        for(int i = 0;i < n;i++) {
            if(!(s[i] == '(' || s[i] == ')')) {
                ans.push_back(s[i]);
            }   
            else if(s[i] == '(' && left_bracket_index[i] == 0) {
                ans.push_back(s[i]);
            }
            else if(s[i] ==')' && right_bracket_index[i] == 0) {
                ans.push_back(s[i]);
            }
        }

        return ans;
        
    }
};