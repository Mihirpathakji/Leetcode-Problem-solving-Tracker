class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //4.Space Optimization : 

        int n = cost.size();
        int first = 0;
        int second = 0;
        int third = -1;

        for(int i = 2; i <= n; i++)
        {
            //cost to reach ith step:
            third = min(cost[i-1] + second, cost[i-2] + first);
            first = second;
            second = third;
        }
        
        return third;

        //TC : O(n)
        //SC : O(1)

    }
};