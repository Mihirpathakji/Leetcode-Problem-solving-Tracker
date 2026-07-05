class Solution {
public:
    string removeStars(string s) {

        string ans;
        int n  = s.length();

        for(int i = 0;i < n;i++) {
            if(s[i]!='*') {
                ans.push_back(s[i]);
            }
            else {
                ans.pop_back();
            }
        }
        return ans;
        
    }
};