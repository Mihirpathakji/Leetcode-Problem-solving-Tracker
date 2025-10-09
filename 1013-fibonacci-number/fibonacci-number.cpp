class Solution {
public:
    int fib(int n) {
      
        if(n==0||n==1)return n;

        else
        {
            // the third,second and the first grows very Largely in the fibonacci numbers hence you need to give them the data type long long int to avoid integer overflow  .

        long long int first=0;
        long long int second=1;

        long long int third=0;

        for(int i=2;i<=n;i++)
        {
            third=first+second;
            first=second;
            second=third;
        }
        // i== n after the for loop ended the i was == n . 

        return third;

        }
    
    }
};