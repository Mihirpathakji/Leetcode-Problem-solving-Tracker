class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char,int>mp1;
        int n = s.length();
        int max1 = 0;
        int max2 = 0;

        for(int i = 0;i < n;i++) {
            mp1[s[i]]++;
        }

        for(int i = 0;i < n;i++) {
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u') {
                max1 = max(max1,mp1[s[i]]);
            }
            else {
                max2 = max(max2,mp1[s[i]]);
            }
        }

        return max1+max2;

        //TC : O(n)
        //SC : O(1)
        
    }
};