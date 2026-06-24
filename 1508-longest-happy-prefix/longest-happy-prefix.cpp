class Solution {
public:
    string longestPrefix(string s) {

        int n = s.length();
        vector<int>lps(n,0);

        int prefix = 0;
        int suffix = 1;

        while(suffix < n)
        {
            if(s[prefix] == s[suffix])
            {
                lps[suffix] = prefix + 1;//Maximum length of common proper prefix suffix till index suff.

                prefix++;
                suffix++;
            }
            else
            {
                if(prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }
                else
                {
                    prefix = lps[prefix-1];
                }
            }
        }

        int limit = lps[n-1];
        string ans;

        for(int i = 0; i < limit;  i++)
        {
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};