class Solution {
public:
    bool isalphanumeric(char ch)
    {
        if((ch>='a' && ch<='z')  ||  (ch>='A' && ch<='Z')|| (ch>='0' && ch<='9'))
        {
            return true;
        }
        return false;
    }


    bool isPalindrome(string s) {
        int n=s.size();
        //Two - pointer Approach:
        int start=0;
        int end=n-1;
        while(start<end)
        {
            if(!isalphanumeric(s[start]))
            {
                start++;//space. 
            }
            if(!isalphanumeric(s[end]))
            {
                end--;
            }
            if((isalphanumeric(s[start])  && isalphanumeric(s[end]) ) && ( tolower(s[start])!=tolower(s[end]) ) )
            {
                return false;
            }
            else if((isalphanumeric(s[start])  && isalphanumeric(s[end]) ) && ( tolower(s[start])==tolower(s[end]) ))
            {
                start++;
                end--;
            }
        } 
        return true;

        //TC:O(n)
        //SC:O(1)
    }
};