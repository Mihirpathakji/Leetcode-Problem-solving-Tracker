class Solution {
public:

    int get_money1(vector<int>& dp,vector<int>&nums,int end_index) {

        if(end_index == 0) {
            return dp[end_index] = nums[end_index]; 
        }

        else if(end_index < 0) {
            return 0;
        }   

        if(dp[end_index]!=-1) {
            return dp[end_index];//Memoization.
        }

        return dp[end_index] = max(nums[end_index] + get_money1(dp,nums,end_index-2),get_money1(dp,nums,end_index-1));

    }

    
    int rob(vector<int>& nums) {

        //Top Down : 

        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

        int end_index = n-2;

        //1.nums from 0 to n-2th :

        vector<int>dp(n,-1);

        int maxi1 = get_money1(dp,nums,end_index);

        //2.nums from 1 to n-1 th.

        vector<int>temp;
        for(int i = 1;i < n;i++) {
            temp.push_back(nums[i]);
        }

        for(int i = 0; i < dp.size();i++) {
            dp[i] = -1;
        }

        end_index = temp.size()-1;

        int maxi2 = get_money1(dp,temp,end_index);

        return max(maxi1,maxi2);

        //TC : O(n)
        //SC : O(n)

        
    }
};