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
            int r=sum%10;//6 1 

            innersum +=r;//6  +1  == 7 
            sum/=10;//1  0 
        }//2^n*logn 
        //innersum got the sum of the digits//1+1 ==2
        return digital_root_recursion(innersum); //7
    }

    int addDigits(int num) {
        //385
        int sum=0;
        while(num!=0)
        {
            int r=num%10;
            sum+=r;//16
            num/=10;
        }
        int x = digital_root_recursion(sum);  
        return x;
    }
};