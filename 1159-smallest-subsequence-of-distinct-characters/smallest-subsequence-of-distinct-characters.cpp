class Solution {
public:
    
    string smallestSubsequence(string s) {

        int n = s.length();

        vector<int>last_index(26,-1);

        for(int i = 0;i < n;i++) {
            last_index[s[i] - 'a'] = i; 
        }

        vector<int>is_in_ans(26,-1);
        stack<char>ans1;//Will contains only distinct characters -> 26 
        string ans;

        for(int i = 0; i < n; i++) {

            if(is_in_ans[s[i] - 'a'] != -1) {
                continue;//No need to put it in the ans again since it is already inserterd once.
            }

            while(!ans1.empty() && ans1.top() > s[i] && last_index[ans1.top() - 'a'] > i ) {

                is_in_ans[ans1.top() - 'a'] = -1;    
                ans1.pop();
            }

            ans1.push(s[i]);
            is_in_ans[s[i] - 'a'] = i;

        }

        while(!ans1.empty()) {
            ans.push_back(ans1.top());
            ans1.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

        //TC : O(n)
        //SC : O(1)
        
    }
};