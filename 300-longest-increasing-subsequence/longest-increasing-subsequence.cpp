class Solution {
public:

    //Top Down -> Biggest 0 to n-1.

    int solve(int next_index,int prev_index,int& n, vector<int>& nums,vector<vector<int>>&dp) {

        if(next_index >= n) {
            return 0;
        }

        if(dp[next_index][prev_index+1]!=-1) {
            return dp[next_index][prev_index+1];
        }

        int take = -1e9;//-1e9.

        if(prev_index < 0 || nums[next_index] > nums[prev_index]) {
            take = 1 + solve(next_index + 1 , next_index,n,nums,dp);//.
        }
        else {
            take = 0;
        }

        int not_take = solve(next_index + 1,prev_index,n,nums,dp);//(1,-1).
        
        return dp[next_index][prev_index+1] = max(take,not_take);

    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        
        int next_index = 0;//next indices : 0 to n-1. -> total n possibilites.
        int prev_index = -1;//previous index == -1 to n-1 -> total n+1 possibilities.

        //dp[0][-1]-> not poss. convert it to dp[0][0]
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(next_index,prev_index,n,nums,dp);//(0,-1).
        //Graph.          

    }
};