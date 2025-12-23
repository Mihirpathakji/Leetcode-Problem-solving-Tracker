class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if((s[i]>=65 && s[i]<=90))
            {
                s[i]+=32;
            }
        }
        //a man,a plan, a canal: panama
        for(int i=0;i<n;i++)
        {//taking only of if there is alpha numeric:
            if((s[i]>=65 && s[i]<=90)|| (s[i]>=97 && s[i]<=122) || (s[i]=='0' ||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'))
            {
                s1.push_back(s[i]);
            }
        }
        int n1=s1.size();
        //check if s1 is palindromic or not:
        int start=0;
        int end=n1-1;
        while(start<end)
        {
            if(s1[start]!=s1[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
        //TC:O(n)
        //SC:O(n)
    }
};