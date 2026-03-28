class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        long long max_len = 0;
        long long curr_len  = 0;

        for(int i = 0 ;i < s.size();i++)
        {
            unordered_map<char,int>mp;
            curr_len = 0;
            for(int j = i ; j < s.size() ; j++ )
            {
                if(mp.find(s[j])!= mp.end())
                {
                    break;
                }
                else
                {
                    curr_len++;
                    mp[s[j]]++;  
                }
            }

            max_len = max(max_len,curr_len);
        
        }
        
        return max_len;

    }

};