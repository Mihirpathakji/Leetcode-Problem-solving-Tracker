class Solution {
public:
    int hammingWeight(int n) {

        //Brute-Force:
        int count1 = 0;
        while(n > 0)
        {
            if(n%2 ==1)
            {
                count1++;
            }   
            n/=2;
        }
        return count1;

        //TC : O(logn)
        //SC : O(1)
    }
};