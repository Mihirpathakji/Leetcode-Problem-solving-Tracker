class Solution {
public:

    int rob(vector<int>& nums) {

        //Bottom - Up : 

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0],nums[1]);
        }

        vector<int>dp(n-1,-1);//0 to (n-2) th. -> n-2+1 == n-1 elements are there.

        dp[0] = nums[0];
     
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i < n-1;i++) {
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        int maxi1 = dp[n-2];//dp[2]. 

        vector<int>dp2(n,-1);//1 to n-1 

        dp2[0] = nums[1];

        dp2[1] = max(nums[1],nums[2]);   
        
        for(int i = 2;i < n-1;i++) {
            dp2[i] = max(nums[i+1] + dp2[i-2],dp2[i-1]); 
        }

        return max(dp2[n-2],maxi1);

    }
};