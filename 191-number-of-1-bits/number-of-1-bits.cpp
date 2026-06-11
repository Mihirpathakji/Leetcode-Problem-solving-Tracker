class Solution {
public:
    int hammingWeight(int n) {

        //Optimal :

        long long int count1 = 0;

        while(n)
        {
            n = (n & (n-1));//12 8 0
            count1++; //1 2 3
        }

        return count1;

        //TC : O(31)worst.
        //SC : O(1)

    }
};