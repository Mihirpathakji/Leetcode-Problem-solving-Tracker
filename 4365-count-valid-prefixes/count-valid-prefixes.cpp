class Solution {
public:
    int countValidPrefixes(string s) {

        int n = s.length();

        int count1 = 0;
        int count0 = 0;
        int counts = 0;

        for(int i = 0;i < n;i++) {
            if(s[i] == '1') {
                count1++;
            }
            else {
                count0++;
            }

            if(count1 == count0 || count1 == count0-1 || count1 == count0+1) {
                counts++;
            }
        }

        return counts;
        
    }
};