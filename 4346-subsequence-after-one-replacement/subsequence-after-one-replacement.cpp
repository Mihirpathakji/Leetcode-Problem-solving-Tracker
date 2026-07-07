class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
       
        int n = s.length();
        int m = t.length();

        vector<int> prefixEnd(n + 1, 1e9);
        prefixEnd[0] = -1;

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                prefixEnd[i + 1] = j;
                i++;
            }
            j++;
        }

        vector<int> suffixStart(n + 1, -1e9);
        suffixStart[n] = m;

        i = n - 1;
        j = m - 1;
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) {
                suffixStart[i] = j;
                i--;
            }
            j--;
        }

    
        for (int k = 0; k < n; k++) {
            int leftBound = prefixEnd[k];
            int rightBound = suffixStart[k + 1];

            if (leftBound != 1e9 && rightBound != -1e9 && rightBound - leftBound > 1) {
                return true;
            }
        }

        return false;
    }
};