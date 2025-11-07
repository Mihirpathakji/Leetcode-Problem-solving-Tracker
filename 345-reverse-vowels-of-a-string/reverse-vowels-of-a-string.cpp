class Solution {
public:

bool is_vowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
    {   
        return true;
    }
    return false;

}
    string reverseVowels(string s) {
        
        int n=s.size();
        int start=0;
        int end=n-1;
        //Two Pointer ma While()loop aj levani .....
        while(start<end)
        {
            //CASES :  
            
            //case1:
           
            if(!is_vowel(s[end]))
            {
                end--;//s[end] ne vowel banavo
            }
           
           //CASE 2  :

            else if(!is_vowel(s[start]))
            {
                start++;//s[start] ne vowel banavo 
            }
           
           //CASE 3 : 
            else
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        
        return s;



    }
};