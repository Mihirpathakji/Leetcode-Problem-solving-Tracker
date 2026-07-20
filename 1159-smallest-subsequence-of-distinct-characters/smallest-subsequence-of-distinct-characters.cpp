class Solution {
public:
    
    string smallestSubsequence(string s) {

        int n = s.length();

        vector<int>last_index(26,-1);

        for(int i = 0;i < n;i++) {
            last_index[s[i] - 'a'] = i; 
        }

        vector<int>is_in_ans(26,-1);
        string ans;

        for(int i = 0; i < n; i++) {

            if(is_in_ans[s[i] - 'a'] != -1) {
                continue;//No need to put it in the ans again since it is already inserterd once.
            }

            while(!ans.empty() && ans.back() > s[i] && last_index[ans.back()-'a'] > i ) {

                is_in_ans[ans.back() - 'a'] = -1;    
                ans.pop_back();
            }

            ans.push_back(s[i]);
            is_in_ans[s[i] - 'a'] = i;

        }

        return ans;

        //TC : O(n)
        //SC : O(1)
        
    }
};