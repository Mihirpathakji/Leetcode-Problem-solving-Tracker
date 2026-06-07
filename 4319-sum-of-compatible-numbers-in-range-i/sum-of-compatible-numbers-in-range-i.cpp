class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int compatibles_sum = 0;//possible values of x == 1 to 1e8 or 1e9

        //If Xmin = (n-k) is negative or zero than start with 1 else start with (n-k).

        //Minimum +ve integer = 1.

        for(int x = max(1,n-k); x <= n + k; x++)
        {
            if( (n & x) == 0 )
            {
                //x is compatible.
                compatibles_sum += x;
            }
        }
        return compatibles_sum;
    }
};