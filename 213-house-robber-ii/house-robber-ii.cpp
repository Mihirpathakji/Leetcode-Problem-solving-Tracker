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

        vector<int>dp(n,-1);//0 to (n-2) th. -> n-2+1 == n-1 elements are there.

        dp[0] = nums[0];
     
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i < n-1;i++) {
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        int maxi1 = dp[n-2];

        //1 to n-1 th.

        vector<int>temp(n,0);
        for(int i = 1;i < n;i++) {
            temp[i] = nums[i]; 
        }

        dp[0] = temp[0];
        dp[1] = max(temp[0],temp[1]);

        for(int i = 2;i < n;i++) {
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        maxi1 = max(maxi1,dp[n-1]);

        return maxi1;

        //TC : O(n)
        //SC : O(n)


    }
};