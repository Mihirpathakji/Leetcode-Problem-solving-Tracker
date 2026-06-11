class Solution {
public:
    int hammingWeight(int n) {

        //Better:

        long long int count1 = 0;
        while(n > 0)
        {
            if(n&1)
            {
           
                //n is odd i.e n%2==1. 
                count1++;
            }   

            n = (n >> 1);
        }

        return count1;

        //TC : O(logn)
        //SC : O(1)

    }
};