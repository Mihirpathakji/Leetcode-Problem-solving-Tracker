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
                x1 = s[l];//
                x2 = s[r];
                break;
            }
        }

        bool ok1 = true;//can be made palindromic if we delete x1 = s[l] once.
        bool ok2 = true;//can be made palindromic if we deleted x2 = s[r] once.

        if(x1 == '0') {
            return true;
        }
        else {

            int removes = 0;
            l = 0;
            r = n-1;
            while(l < r) 
            {   
                if(s[l] == s[r]) {
                    l++;
                    r--;
                }
                else {
                    if( (s[l] == x1)  && ( removes == 0) ) {
                        l++;
                        removes++;//1
                    }
                    else if(s[r] == x1 && removes == 0){
                        removes++;
                        r--;
                    }
                    else {
                        ok1 = false;
                        break;
                    }
                }
            }

            removes = 0;
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
                        if( (s[l] == x2)  && ( removes == 0) ) {
                            l++;
                            removes++;//
                        }
                        else if(s[r] == x2 && removes == 0){
                            removes++;//1
                            r--;
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