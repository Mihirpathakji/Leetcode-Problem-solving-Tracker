class Solution {
public:
    string processStr(string s) {

        int n = s.length(); 
        stack<char>st;//g
        stack<char>rev;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '*')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(s[i] == '#')
            {
                stack<char>temp;
                temp = st;//a

                stack<char>temp2;
                while(!temp.empty())
                {
                    temp2.push(temp.top());
                    temp.pop();
                }
                //O("cba").

                while(!temp2.empty())
                {
                    st.push(temp2.top());//[abcabc]
                    temp2.pop();
                }

            }
            else if(s[i] == '%')
            {   
                while(!st.empty())
                {
                    rev.push(st.top());//g
                    st.pop();
                }

                st = rev;//g

                //Empty() the rev for another % comes in future.
                
                while(!rev.empty())
                {
                    rev.pop();//
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        //stack to string.
        //st = "".st.top() = 'ab'.

        //We can access st.top() in stack.
        //s = 'ab'

        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());//g
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};