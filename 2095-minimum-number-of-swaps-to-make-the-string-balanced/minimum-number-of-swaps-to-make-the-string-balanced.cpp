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

        return ceil(float(m)/2);

        //TC : O(n)
        //SC : O(n)

    }
};