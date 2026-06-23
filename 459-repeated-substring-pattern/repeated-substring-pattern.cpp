class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        //take every possible Prefix substring :-
        
        int n = s.length();

        for(int j = n/2;j >= 1;j--)
        {
            if(n % j == 0)
            {
                string temp = s.substr(0,j);

                string making = temp;
                int times = n/j;
                while(times--)
                {
                    if(making == s)
                    {
                        return true;
                    }
                    making += temp;
                }
            }
        }   

        return false;


        //TC : O(n*(sqrt(n)))
        //SC : O(n)
    }
};