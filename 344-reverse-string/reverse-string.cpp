class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        int j=n-1;//4
        while(i<j)
        {
            char temp=s[i];//'e'
            s[i]=s[n-i-1];//s[0]=s[4]='o';s[1]=s[5-1-1]=s[3]='l'
            s[n-i-1]=temp;//s[4]='h'//s[3]='e'
            i++;//1//2
            j--;//3//2
            //['o' 'l' 'l' 'e' 'h']
        }
    }

};