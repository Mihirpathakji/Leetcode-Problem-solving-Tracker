class Solution {
public:
    string mergeCharacters(string s, int k) {

        int n = s.size();
        string ans = "";
        unordered_map<char,int>mp;//<char,least_index_of_that_char_from_left>.

        int deletion_cnt = 0;

        for(int i = 0 ; i < n; i++)
        {
            if( mp.find(s[i]) != mp.end() )
            {
                // (i - deletion_cnt ) = index of element in new string formed after some possible Merges. 
                if((i - deletion_cnt) - mp[s[i]]  <= k)
                {
                    deletion_cnt++;
                }
                else
                {
                    ans.push_back(s[i]);
                    //present in map but merge is not possible .Now made it present at the Least new index.
                    mp[s[i]] = i - deletion_cnt;
                }
            }
            else
            {
                mp[s[i]] = i - deletion_cnt;
                ans.push_back(s[i]);
            }
        }

        return ans;
        
    }
};