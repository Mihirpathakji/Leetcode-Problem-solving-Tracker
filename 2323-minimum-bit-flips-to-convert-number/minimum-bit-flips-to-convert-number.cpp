class Solution {
public:
    int minBitFlips(int start, int goal) {

        int target = start^goal;

        //answer is Number of set bits in target.
       
        long long int count = 0;
       
        while(target)
        {   
            target = (target & (target-1));//Keep on Removing rightmost zeroes.
            count++;
        }

        return count;

        //TC : O(31)
        //SC : O(1)
        
    }
};