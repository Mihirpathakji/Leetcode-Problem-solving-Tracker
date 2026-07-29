class Solution {
public:
    string smallestPalindrome(string s) {
       
        int n = s.length();

        vector<int>counts(26,0);
        vector<int>needed(26,-1);

        for(int i = 0;i < n;i++) {
            counts[s[i]-'a']++;
        }

        string ans = "";
        set<char>st(s.begin(),s.end());

        for(auto it : st) {

            int temp_count = counts[it-'a']/2;

            while(temp_count--) {
                ans.push_back(it);
            }

            if(counts[it-'a'] % 2 == 1) {
                needed[it-'a'] = 1;
            }

        }

        string temp = ans;

        for(auto it : st) {
            if(needed[it-'a'] == 1) {
                ans.push_back(it);
            }
        }

        reverse(temp.begin(),temp.end());

        ans += temp;

        return ans;

    }
};