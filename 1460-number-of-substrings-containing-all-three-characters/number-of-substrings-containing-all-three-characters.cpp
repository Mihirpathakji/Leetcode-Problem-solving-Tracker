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
                count_a++;//1
            }

            else if(s[j] == 'b') {
                count_b++;
            }
            else {
                count_c++;
            }

            while(count_a && count_b && count_c) {
                ans += (n-j);//1 2 

                if(s[i] == 'a') {
                    count_a--;//0
                }   

                else if(s[i] == 'b') {
                    count_b--;//0 
                }  

                else {
                    count_c--;
                }

                i++;//1 2
            }

            j++;//3 4
             
        }    
        return ans;


    }
};