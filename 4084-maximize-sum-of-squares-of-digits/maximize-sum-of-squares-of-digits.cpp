class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        
        if(sum > num*9) {
            return "";
        }

        string ans = "";

        int num_9 = sum/9;
        //

        while(num_9) {
            ans += "9";//
            num_9--;//
        }

        int remaining_digit = sum%9;//
        
        if(remaining_digit)
        ans += to_string(remaining_digit);//

        int num_zeroes = num - ans.length();

        while(num_zeroes) {
            ans += "0";
            num_zeroes--;
        }

        return ans;//

    }
};