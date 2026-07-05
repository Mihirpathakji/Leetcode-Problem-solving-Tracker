class Solution {
public:
   
    int minOperations(string s1, string s2) {

        if(s1 == "1" && s2 == "0") {
            return -1;
        }

        int min_ops = 0;

        int n = s1.length();    

        for(int i = 0;i < n;i++) {

            if(s1[i] == s2[i]) {
                continue;
            }   
            else if(s1[i] == '0' && s2[i] == '1') {
                min_ops++;
                s1[i] = '1';
            }
            else if(s1[i] == '1' && s2[i] == '0') {
                if(i+1!=n && s1[i+1] == '1') {
                    min_ops++;//1
                    s1[i+1] = '0';
                }
                else if(i+1!=n && s1[i+1]=='0') {
                    min_ops+=2;
                }
                else {

                    if(i+1==n) {
                        if(i-1>=0) {
                            if(s1[i-1] == '1') {
                                min_ops+=2;
                            }
                            else {
                                min_ops += 2;
                            }
                        }
                    }
                }
            }
        }

        return min_ops;
        
        //TC : O(n)
        //SC : O(1)
        
    }
};