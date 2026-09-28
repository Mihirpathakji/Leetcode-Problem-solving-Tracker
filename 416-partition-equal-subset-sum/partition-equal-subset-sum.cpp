class Solution {
public:

       bool solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp) {
           
        if(dp[index][target] != -1) {
            return dp[index][target];
        }   
        
        if(target == 0) {
            return dp[index][target] = 1;
        }
           
        if(index == 0) {
        
            if(arr[index] == target) {
                return dp[index][target] = 1;
            }
            else {
                return dp[index][target] = 0;
            }
        }
        
        bool take = false;
        if(arr[index] <= target) {
            take = solve(index-1,target-arr[index],arr,dp);
        }
        
        bool no_take = solve(index-1,target,arr,dp); 
        
        if(take || no_take) {
            return dp[index][target] = 1;
        }
        
        return dp[index][target] = 0;
 
    }

    bool canPartition(vector<int>& arr) {


        int n = arr.size();
        int index = n-1;

        int sum = 0;

        for(int i = 0;i < n;i++) {
            sum += arr[i];
        }

        if(sum%2 != 0) {
            return false;
        }

        int target = sum/2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        solve(index,target,arr,dp);
        
        return dp[n-1][target];

    }
};