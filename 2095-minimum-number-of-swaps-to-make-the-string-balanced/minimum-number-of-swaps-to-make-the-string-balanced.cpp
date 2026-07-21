class Solution {
public:
    int minSwaps(string s) {


        int n = s.length();
        stack<char>st;

        for(int i = 0;i < n;i++) {
            
            //Insert only the Opening brackets.
           
            if(s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(!st.empty()) {
                    st.pop();
                }
            }
        }

        int m = st.size();

        if(m%2 == 0) {
            return m/2;
        }
        
        return (m+1)/2;

        //TC : O(n)
        //SC : O(n)

    }
};