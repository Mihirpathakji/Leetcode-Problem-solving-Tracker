class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int i = 0;
        int j = 0;

        unordered_map<char,int>mp;
        int maxi = 0;

        while(j < n) {

           int max_freq = 0;

            mp[s[j]]++;

            for(auto it : mp) {
                max_freq = max(max_freq,it.second);
            }
 
            while( ((j-i+1) - max_freq ) >  k) {

                mp[s[i]]--;

                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }

                i++;
            }

            maxi = max(maxi,j-i+1);

            j++;

        }

        return maxi;
    
        //TC : O(2*n)
        //SC : O(n)
         
    }
};