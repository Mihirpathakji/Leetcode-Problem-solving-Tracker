class Solution {
public:
    string removeOuterParentheses(string s) {

        unordered_set<int>st;
        stack<int>st1;
        int i = 0;
        int n = s.length();

        for(int j = 0;j < n;j++) {
            if(s[j] == '(') {
                st1.push(s[j]);
            }
            else if(!st1.empty() && s[j] == ')') {
                st1.pop();

                if(st1.empty()) {
                    st.insert(i);
                    st.insert(j);//{0,5,6,9}
                    i = j+1;//{6,10}
                }
            }
        }
        
        string ans;
        for(int i = 0;i <n;i++) {
            if(st.find(i)!=st.end()) {
                continue;
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
        //TC : O(n)
        //SC : O(n)
        
    }
};