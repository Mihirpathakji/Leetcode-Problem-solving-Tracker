class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //3.Bottom Up Approach : 
        //1.start inserting the base cases into the dp :

        int n = cost.size();

        //3.for loop replace functions by dp : 

        int first = 0;
        int second = 0;
        int third = -1;

        for(int i = 2; i <= n; i++)
        {
            //cost to went to ith step:
            third = min(cost[i-1] + second, cost[i-2] + first);
            first = second;
            second = third;
        }
        
        return third;
        
        //TC : O(n)
        //SC : O(n)

    }
};