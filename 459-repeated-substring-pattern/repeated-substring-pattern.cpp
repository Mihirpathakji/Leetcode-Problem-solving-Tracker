class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        //take every possible Prefix substring :-
        
        int n = s.length();

        for(int j = n/2-1;j >= 0;j--)
        {
            if(n % (j+1) == 0)
            {
                string temp = s.substr(0,j+1);

                string making = temp;
                int times = n/(j+1);
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