class Solution {
public:
    bool checkOnesSegment(string s) {

        int l = 0;

        int no_consecutive_seg = 0;

        while(l < s.size() && s[l] =='1')
        {
            l++;
        }
        //l -> '0'

        while(l < s.size() && s[l] == '0')
        {
            l++;
        }
        return l == s.size();

        //TC:O(n)
        //SC:O(1)

    }
};