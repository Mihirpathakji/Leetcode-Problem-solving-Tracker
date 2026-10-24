class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int i = 0;
        int j = 0;

        unordered_map<char,int>mp;
        int maxi = 0;
        int max_freq = 0;

        while(j < n) {


            mp[s[j]]++;

            max_freq = max(max_freq,mp[s[j]]);

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
    
        //TC : O(n + n) = O(n)
        //SC : O(n)
         
    }
};