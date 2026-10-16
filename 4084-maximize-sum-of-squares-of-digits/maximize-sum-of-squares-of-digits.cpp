class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        
        if(sum > num*9) {
            return "";
        }

        string ans = "";

        int num_9 = sum/9;//0.1.
        //

        while(num_9) {
            ans += "9";//9.
            num_9--;//0.

            if(sum >=9) {
                sum-=9;//1.
            }
        }

        //We cannot add 9. Bcz now adding 9 is gonna increasing the sum value.
        //than the required one.


        int remaining_digit = sum;//
        
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