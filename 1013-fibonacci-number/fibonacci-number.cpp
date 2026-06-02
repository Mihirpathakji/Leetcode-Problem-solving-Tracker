class Solution {
public:
    int fib(int n) {

        //4.Space Optimization.

        if(n <= 1)
        {
            return n;
        }

        int first = 0;
        int second = 1;
        int third;

        for(int i = 0 ; i <= n - 2 ; i++)
        {
            third = first+second;
            first = second;
            second = third;
        }

        return third;

    }
};