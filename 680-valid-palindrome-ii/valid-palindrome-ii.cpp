class Solution {
public:
    bool validPalindrome(string s) {

        int n = s.length();
        int l = 0;
        int r = n - 1;
        char x1 =  '0';
        char x2 =  '0';

        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                x1 = s[l];//'a'
                x2 = s[r];//'c'
                break;
            }
        }

        bool ok1 = true;//can be made palindromic if we delete x1 = s[l] once.
        bool ok2 = true;//can be made palindromic if we deleted x2 = s[r] once.

        if(x1 == '0') {
            return true;
        }
        else {

            int removes = 0;//
            while(l < r) 
            {   
                if(s[l] == s[r]) {
                    l++;
                    r--;
                }
                else {
                    if( (s[l] == x1)  && ( removes == 0) ) {
                        l++;//1 
                        removes++;//1
                    }
                    else {
                        ok1 = false;
                        break;
                    }
                }
            }

            removes = 0;//we are removing the x2 = s[r].we need the correct count of removals of x2 = s[r].

            if(ok1) {
                return true;                                        
            }
            else {
                l = 0;
                r = n-1;
                while(l < r) 
                {   
                    if(s[l] == s[r]) {
                        l++;
                        r--;
                    }
                    else {
                        if(s[r] == x2 && removes == 0){
                            removes++;//1  
                            r--;//
                        }
                        else {
                            ok2 = false;
                            break;
                        }
                    }
                }

                if(ok2) {
                    return true;
                }
            }
        }

        return false;
        
    }
};