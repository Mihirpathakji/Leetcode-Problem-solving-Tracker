class Solution {
public:
    int longestContinuousSubstring(string s) {

        //Sliding window :

        int n = s.length();
        int i = 0;
        int j = 1;
        int max_len = 0;
        int counter = 1;

        while(j < n) {

            //Consecutives are founded.    
            if((s[j] -'0') == (s[j-1] - '0' + 1)) {
                counter++;//2
            }
            else {
                i = j;
                max_len = max(max_len,counter);//2
                counter = 1; 
            }
            j++;

        }
        
        max_len = max(max_len,counter);
        return max_len;
        
        
    }
};