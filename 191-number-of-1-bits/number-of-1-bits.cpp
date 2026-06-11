class Solution {
public:
    int hammingWeight(int n) {

        //Better:

        long long int count1 = 0;
        while(n > 0)
        {
            if(n &1)
            {//n is odd 
                count1++;
            }   

            n = (n >> 1);
        }

        return count1;

        //TC : O(logn) worst O(31)
        //SC : O(1)

    }
};