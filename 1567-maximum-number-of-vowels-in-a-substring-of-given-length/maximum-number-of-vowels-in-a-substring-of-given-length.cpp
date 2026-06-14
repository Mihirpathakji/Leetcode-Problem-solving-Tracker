class Solution {
public:


    bool is_vowel(char ch)
    {   
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' ||ch == 'u');
    }
    int maxVowels(string s, int k) {

        //Sliding window:

        int i = 0;
        int j = 0;
        int n = s.length();

        int max_vowels = INT_MIN;
        int curr_vowels = 0;//Vowels count in the current window.

        while(j < n)
        {
            if(is_vowel(s[j]))
            {
                curr_vowels++;
            }

            if(j - i + 1 == k)
            {
                max_vowels = max(max_vowels,curr_vowels);

                //shrink the window.    
                if(is_vowel(s[i]))
                {
                    curr_vowels--;
                }
                 i++;
            }
            j++;
        }

        return max_vowels;

        //TC : O(n)
        //SC : O(1)


    }
};