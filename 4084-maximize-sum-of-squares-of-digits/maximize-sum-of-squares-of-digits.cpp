class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        
        //ans = n(string).
        //for so many n we need to return it's maximum one.

        //num = 2. sum = 20. 99 => 9*num == 18

        //num = 3 => Maximum = 999. Maximum possible sum of digit from a number containing num 
        //number of the digits = num*9.

        if(sum > num*9) {
            return "";
        }

        string ans = "";

        int num_9 = sum/9;

        while(num_9) {
            ans += "9";
            num_9--;
        }

        int remaining_digit = sum%9;
        
        if(remaining_digit)
        ans += to_string(remaining_digit);

        int num_zeroes = num - ans.length();

        while(num_zeroes) {
            ans += "0";
            num_zeroes--;
        }

        return ans;

    }
};