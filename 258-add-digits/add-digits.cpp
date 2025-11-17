class Solution {
public:

    int digital_root_recursion(int sum)
    {
        if(sum==0)
        {
            return 0;
        }
        if(sum%10==sum)
        {
            return sum;//7
        }
        // sum is not a single digit number than compute it's inner sum     
        int innersum=0;
        while(sum!=0)
        {
            int r=sum%10;//5  8  3     6    1
            innersum +=r;//5   13  16    6   7 
            sum/=10;//38  3  0   1  0  
        }
        //innersum got the sum of the digits//1+1 ==2
        return digital_root_recursion(innersum); //385   16    7
    }
    int addDigits(int num) {
        //385
        int x = digital_root_recursion(num);  
        return x;
    }
};