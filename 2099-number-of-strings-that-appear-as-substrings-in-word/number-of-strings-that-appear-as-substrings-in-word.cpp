class Solution {
public:

    bool kmp(string pattern,string word) {

        int n = word.length();
        int m = pattern.length();
        
        //Compute lps vector for the pattern.

        vector<int>lps(m,0);

        int i = 0;
        int j = 1;

        while(j < m) {

            if(pattern[i] == pattern[j]) {
                lps[j] = i+1;
                //i wanted to cumulate that how many numbers are further matching.
                i++;
                j++;            
            }   

            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                }
                else {
                    i = lps[i-1];
                }
            }
        }    

        //Now match :

        i = 0;
        j = 0;

        while(i < n && j < m) {

            if(word[i] == pattern[j]) {
                i++;
                j++;
            }

            else {

                if(j == 0) {
                    i++;        
                }   
                else {
                    j = lps[j-1];
                }
            }
        }  
        if(j == m) {
            return true;
        }

        return false;

    }

    int numOfStrings(vector<string>& patterns, string word) {
        
        int counts = 0;
        for(auto str : patterns) {

            if(kmp(str,word)) {
                counts++;
            }
        }

        //kmp check that whether str exists as a substring in word or not.

        return counts;
        
    }
};