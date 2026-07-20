class Solution {
public:

    string removeDuplicateLetters(string s) {

        int n = s.length();

        vector<int>last_indices(26,-1);
        vector<int>my_ans(26,-1);
     
        for(int i = 0;i < n;i++) {
            last_indices[s[i]-'a'] = i;
        }

        string ans;

        for(int i = 0;i < n;i++) {

            if(my_ans[s[i]-'a'] !=-1) {
                continue;
            }

            int ch = s[i];
            int index = ch-'a';

            while(!ans.empty() && ans.back() > ch && last_indices[ans.back()-'a'] > i) {
                my_ans[ans.back()-'a'] = -1;
                ans.pop_back();
            }

            ans.push_back(ch);
            my_ans[index] = i;
        
        }
        
        return ans;

        //TC : O(n)
        //SC : O(1)
        
    }
};