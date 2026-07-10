class Solution {
public:
   
    int longestContinuousSubstring(string s) {

        //bethu sliding window chapo:
        
        int n = s.length();
        int j = 0;
        int current_counter = 1;

        int max_len = 0;
        
        while(j < n-1) {

            if(s[j+1] == s[j] + 1) {
                current_counter++;
            }
            else {
                max_len = max(max_len,current_counter);
                current_counter = 1;
            }
            j++;
        }

        max_len = max(max_len,current_counter);

        return max_len;

    }
};