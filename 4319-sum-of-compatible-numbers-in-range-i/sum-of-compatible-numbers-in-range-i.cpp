class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int compatibles_sum = 0;//possible values of x == 1 to 1e8 or 1e9

        for(int x = 1; x <= 1e6; x++)
        {
            if((n & x) == 0 && (abs(n - x) <= k))
            {
                //x is compatible.
                compatibles_sum += x;
            }
        }
        return compatibles_sum;
    }
};