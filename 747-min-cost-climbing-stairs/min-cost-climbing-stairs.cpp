class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //4.Space Optimization : 

        int n = cost.size();

        //Base case :         

        int first = 0;//f(0) -> minimum cost to reach 0th step.
        int second = 0;//f(1) -> minimum cost to reach 1th step.

        int third = -1;

        for(int i = 2; i <= n; i++)
        {
            //cost to reach ith step:
            //cost[2] = min(cost[1]+ )
            third = min(cost[i-1] + second, cost[i-2] + first);
            first = second;
            second = third;
        }
        
        return third;

        //TC : O(n)
        //SC : O(1)

    }
};