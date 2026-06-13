class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char>ss;//for s
        stack<char>st;//for t

        for(int i = 0 ; i< s.size(); i++)
        {
            if( s[i] != '#' )
            {   
                ss.push(s[i]);
            }
            else
            {
                if(!ss.empty())
                ss.pop();
            }
        }

        for(int i = 0;i < t.size(); i++)
        {
            if( t[i] != '#' )
            {
                st.push(t[i]);
            }
            else
            {   
                if(!st.empty())
                st.pop();
            }
        }

        return ss == st;

        //TC : O(s+t)
        //SC : O(s+t)
        
    }
};