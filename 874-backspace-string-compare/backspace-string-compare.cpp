class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<int>st1;
        stack<int>st2;

        //For string s:
        for(int i=0;i<s.size();i++)
        {
            if(st1.empty() && s[i]!= '#')
            {
                st1.push(s[i]);
            }
            else if(!st1.empty() && s[i] =='#')
            {
                st1.pop();
            }
            else if(s[i] != '#')
            {
                st1.push(s[i]);
            }
        }

        for(int i=0;i<t.size();i++)
        {
            if(st2.empty() && t[i] !='#')
            {
                st2.push(t[i]);
            }
            else if(!st2.empty() && t[i] =='#')
            {
                st2.pop();
            }
            else if(t[i] !='#') 
            {
                st2.push(t[i]);
            }
        }

        return st1 == st2;

        //TC:O(n+m)
        //SC:O(n+m)
    }
};