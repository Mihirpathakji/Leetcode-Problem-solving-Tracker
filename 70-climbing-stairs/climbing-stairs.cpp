class Solution {
public:
    int climbStairs(int n) {

        //4. Space Optimization : 

        //Here the no. of distinct ways to climb the nth stairs depends on the number of distinct ways to climb the (n-1)th stair and (n-2)th stair only.

        //since every ith depend only on (i-1)th and (i-2)th only.No need to create a extra vector.We can store these two values of climbStairs[i-1] and climbStairs[i-2] in a single variable only.    

        if(n <= 1)
        {
            return 1;//f(0),f(1)
        }

        int prev1 = 1;//f(0)=1
        int prev2 = 1;//f(1)=1
        int ans = 0;

        for(int i = 0; i <= n-2 ;i++)
        {
            ans = prev1 + prev2;
            prev1 = prev2;//first = second
            prev2 = ans;//second = third. 
        }

        return ans;

        //TC : O(n)
        //SC : O(1)

    }
};