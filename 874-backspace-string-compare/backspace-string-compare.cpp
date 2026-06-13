class Solution {
public:
    bool backspaceCompare(string s, string t) {

        //Most Optimal : Two - Pointer Approach :

        int i = s.size()-1;
        int j = t.size()-1;
        int skips_s = 0;
        int skips_t = 0;

        while(i >=-1 && j >=-1)
        {
            while(i >=0 )
            {
                //case1 :
                if(s[i] == '#')
                {
                    skips_s++;
                    i--;
                }
                //case2 :Is any character. 
                //Can we skip it?
               
                else if(skips_s > 0)
                {
                    skips_s--;
                    i--;
                }

                else
                {
                    break;
                }
            }

            while(j >=0)
            {
                //case1 : #
                if(t[j] == '#')
                {
                    skips_t++;
                    j--;
                }

                //character can we skip it?

                else if(skips_t > 0)
                {
                    skips_t--;
                    j--;
                }

                else
                {
                    break;
                }

            }

            char first;
            if(i!=-1)
            {
                first = s[i];//'c'
            }   
            else
            {
                first = '$';//an character which was not there in string. 
            }

            char second;
            if(j!=-1)
            {
                second = t[j];//''b
            }
            else
            {
                second = '$';
            }

            if(first == second)
            {
                //Check if every of their characters are equal or not.
                i--;
                j--;
            }
            
            else
            {
                return false;
            }
        }
        return true;

        //TC : O(s + t)
        //SC : O(1)
        
    }
};