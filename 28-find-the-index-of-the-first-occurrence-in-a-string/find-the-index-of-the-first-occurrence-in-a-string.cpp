class Solution {
public:
    int strStr(string haystack, string needle) {


        int n = haystack.size();
        int m = needle.size();

        vector<int>lps(m,0);
        
        //Compute the lps of needle:

        int prefix = 0;
        int suffix = 1;

        while(suffix < m)
        {
            //Comparision :

            if(needle[prefix] == needle[suffix])
            {
                lps[suffix] = prefix+1;//length of lcps ending at index suffix.
                prefix++;
                suffix++;
            }
            else
            {
                if(prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }
                else
                {
                    prefix = lps[prefix-1];
                }
            }
        }//O(m)

        int first = 0;
        int second = 0;

        while(first < n)
        {
            if(second == m)
            {
                return first-second;               
            }
            
            if(haystack[first] == needle[second])
            {
                first++;
                second++;
            }
            else
            {
                if(second == 0)
                {
                    first++;
                }
                else
                {
                    second = lps[second-1];
                }
            }

        }//O(n)

        if(first ==n && second==m)
        {
            return first-second;
        }

        return -1;

        //TC : O(n+m)
        //SC : O(m)



    }
};