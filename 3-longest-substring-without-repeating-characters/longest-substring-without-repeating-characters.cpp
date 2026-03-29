class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<bool>count(256,0);

        int first =  0;
        int second = 0;

        long long max_len = 0;

        while(second < s.size())
        {//O(n)

            while(count[s[second]])
            {
                count[s[first]] = 0;//Removed the Repeating characters from the window.
                first++;//Shrink window from the left side.
            }
            count[s[second]] = 1;//Add this new character to window.
            max_len = max((int)max_len, second - first +1);
            second++;//Expand the window.
        }

        return max_len;
        //abcdefghijklmnoo//O(N) + O(N) == O(2* N)

    }
};