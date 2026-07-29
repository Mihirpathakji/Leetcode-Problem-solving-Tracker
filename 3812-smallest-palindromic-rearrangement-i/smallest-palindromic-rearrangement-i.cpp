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
      
        set<char>st(s.begin(),s.end());//Sorted order we needed.And no duplicates.
        //O(n*log(26)) // n*log(SET SIZE).

        for(auto it : st) {

            int temp_count = counts[it-'a']/2;//1 1 1 

            while(temp_count--) {
                ans.push_back(it);//ab //[a c d]. 
            }

            if(counts[it-'a'] % 2 == 1) {
                needed[it-'a'] = 1;
            }

        }//O(1).

        string temp = ans;//abd

        for(auto it : st) {
            if(needed[it-'a'] == 1) {
                ans.push_back(it);
            }
        }//O(1).

        reverse(temp.begin(),temp.end());//dca

        ans += temp;

        return ans;
        
        //TC : O(n*log(Maximum set size)) == O(n*log(26)).
        //SC : O(n).//->ans.

    }
};