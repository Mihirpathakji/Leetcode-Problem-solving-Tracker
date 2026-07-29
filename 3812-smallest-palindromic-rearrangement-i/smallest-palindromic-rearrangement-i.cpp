class Solution {
public:
    string smallestPalindrome(string s) {
       
        int n = s.length();
        if(n == 1) {
            return s;
        }

        vector<int>counts(26,0);
        vector<int>taken(26,-1);
        vector<int>needed(26,-1);

        for(int i = 0;i < n;i++) {
            counts[s[i]-'a']++;//
        }

        string ans = "";
        set<char>st(s.begin(),s.end());//[ab]//[z].//[rur]

        for(auto it : st) {
            int temp_count = counts[it-'a']/2;//1.1.0.//1.0.
            if(temp_count) {
                taken[it-'a'] = 1;
            }
            while(temp_count--) {
                ans.push_back(it);//ab // r
            }
            if(counts[it-'a']%2 == 1) {
                needed[it-'a'] = 1;
            }
        }

        string temp = ans;//ab "" //r.//r.

        for(auto it : st) {
            if(taken[it-'a'] == -1 || (needed[it-'a'] ==1)) {
                ans.push_back(it);
            }//ru
        }

        reverse(temp.begin(),temp.end());//ba //r.

        ans += temp;//abbba //
        return ans;


    }
};