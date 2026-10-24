class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int i = 0;
        int j = 0;

        unordered_map<char,int>mp;
        int max_freq = 0;//0.
        int maxi = 0;//0.

        while(j < n) {

            mp[s[j]]++;//1.

            max_freq = max(max_freq,mp[s[j]]);//1.//1.
 
            while( ((j-i+1) - max_freq ) >  k) {

                mp[s[i]]--;

                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }

                i++;
            }

            maxi = max(maxi,j-i+1);///1.

            j++;//1.

        }

        return maxi;
         
    }
};