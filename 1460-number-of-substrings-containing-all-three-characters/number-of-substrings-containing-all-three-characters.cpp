class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        int i = 0;
        int j = 0;
        int ans = 0; 

        while(j < n) {

            if(s[j] == 'a') {
                count_a++;
            }

            else if(s[j] == 'b') {
                count_b++;
            }
            else {
                count_c++;
            }

            while(count_a>=1 && count_b>=1 && count_c>=1) {
                ans += (n-j);

                if(s[i] == 'a') {
                    count_a--;
                }   

                else if(s[i] == 'b') {
                    count_b--;
                }  

                else {
                    count_c--;
                }

                i++;
            }

            j++;
             
        }    

        return ans;
        
        //TC : O(n)
        //SC : O(1)

    }
};