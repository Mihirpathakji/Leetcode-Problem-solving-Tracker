class Solution {
public:
    bool checkOnesSegment(string s) {

        int l = 0;
        int r = 0;

        int cnt = 0;

        while(r  < s.size())
        {
            if(s[l] == '1')
            {
                while(r < s.size())
                {
                    if(s[r] == '1')
                    {
                        if(r == s.size()-1)
                        {
                            cnt++;
                        }
                        r++;
                        l++;
                    }
                    else
                    {
                        if(s[r-1] == '1')
                        {
                            cnt++;
                        }
                        r++;
                        l++;
                    }
                }
            }
        }

        return cnt <=1;
        
    }
};