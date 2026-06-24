class Solution {
public:
    string longestPrefix(string s) {

        //KMP Algorithm : To find the longest Proper common prefix which is also a proper suffix.

        int n = s.length();
        vector<int>lps(n,0);//longest prefix suffix.

        int prefix = 0;
        int suffix = 1;

        while(suffix < n)
        {
            if(s[prefix] == s[suffix])
            {
                lps[suffix] = prefix + 1;//Maximum length of common proper prefix and proper suffix for a string which ends at index suffix.
                
                prefix++;
                suffix++;
            }
            else
            {
                if(prefix == 0)
                {
                    lps[suffix] = 0;//I cannot send the prefix to backwards further since it will become negative.thereby lps[-1] not accessible.
                    suffix++;
                }
                else
                {
                    prefix = lps[prefix-1];
                }
            }
        }

        int limit = lps[n-1];//Contains the index "before" which all elements forms the longest common proper prefix suffix for the given entire string.

        string ans;

        for(int i = 0; i < limit;  i++)
        {
            ans.push_back(s[i]);
        }
        
        return ans;
        
        //TC : O(n)
        //SC : O(n)


    }
};