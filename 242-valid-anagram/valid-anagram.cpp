class Solution {
public:
    bool isAnagram(string s, string t) {

        //Frequency of all chars in t must be same as s .

        unordered_map<char,int>mp1;//t
        for(int i  =0; i < t.length();i++) {
            mp1[t[i]]++;
        }
        
        
        unordered_map<char,int>mp2;//s
        for(int i  =0; i < s.length();i++) {
            mp2[s[i]]++;
        }

        if(t.length() != s.length()) {
            return false;
        }

        for(int i = 0;i < t.length();i++) {
            if(mp1[t[i]]!=mp2[t[i]]) {
                return false;
            }   
        }
        return true;
    }
};