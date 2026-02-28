class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        stack<char>st1;
        for(int i =0;i<s.size();i++)
        {
            st1.push(s[i]);
        }

        int i=0;
        while(st1.size())
        {
            s[i] = (st1.top());
            st1.pop();
            i++;
        }


        //TC:O(n)
        //SC:O(n)

    }

};