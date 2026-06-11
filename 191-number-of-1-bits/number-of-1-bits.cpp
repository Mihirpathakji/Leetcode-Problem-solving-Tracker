class Solution {
public:
    int hammingWeight(int n) {

        //Optimal :

        long long int count1 = 0;
        while(n )
        {
            n = (n & (n-1));
            count1++; 
        }

        return count1;

        //TC : O(31)worst.
        //SC : O(1)

    }
};