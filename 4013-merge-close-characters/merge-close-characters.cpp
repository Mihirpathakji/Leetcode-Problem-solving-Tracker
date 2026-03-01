class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        int n = s.size(); 
        int deletion_cnt = 0;
        string ans  = "";
        
        unordered_map<char,int>mp;

        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(i - deletion_cnt - mp[s[i]] <= k)
                {
                    //Merge pair Present and Merge is possible 
                    deletion_cnt++;
                }
                else
                {
                    //Merge is not possible but Keep track of smallest Left index for that s[i].
                    mp[s[i]] = i - deletion_cnt; // i - deletion_cnt is index of that another copy of s[i] in the string after deletion.
                    ans.push_back(s[i]);
                }
            }
            else
            {
                // this element is not present in the map already.
                mp[s[i]] = i - deletion_cnt;// i - deletion cnt will be index of the first Occurance of that string .
                ans.push_back(s[i]);
            }
        }

        return ans;
        
        //TC:O(n)
        
    
    }
};