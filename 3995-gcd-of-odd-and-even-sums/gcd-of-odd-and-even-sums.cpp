class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        long double odd_sum = 0;//O(1)
        
        long double mul1 = (double)n/2;//2.5

        long long mul2 = (2*1 + (n-1)*2);

        odd_sum = (mul1*mul2);

        long double even_sum = 0;
        
        mul1 = (double)n/2;

        mul2 = (2*2 + (n-1)*2);

        even_sum = (mul1*mul2);

        int sum1 = odd_sum;
        int sum2 = even_sum;
        
        return __gcd(sum1,sum2);//log(min(sum1,sum2)).

    }
};