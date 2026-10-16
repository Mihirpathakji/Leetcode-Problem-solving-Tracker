class Solution {
public:

    string maxSumOfSquares(int num, int sum) {
        
        if(sum > num*9) {
            return "";
        }

        string ans = "";

        int num_9 = sum/9;//11111
        //

        while(num_9) {
            ans += "9";
            num_9--;

            if(sum >=9) {
                sum-=9;
            }
        }//O(sum).

        int remaining_digit = sum;
        
        if(remaining_digit)
        ans += to_string(remaining_digit);//O(1).

        int num_zeroes = num - ans.length();

        while(num_zeroes) {
            ans += "0";
            num_zeroes--;
        }

        return ans;

        //O(n)


        //TC : O(num)
        //SC : O(num) 
    }
};