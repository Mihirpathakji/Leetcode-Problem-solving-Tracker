class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        long long n = nums.size();
        long long maxi = INT_MIN;

        long long prefix = 0;
        
        for(long long i  = 0 ; i < n; i++)
        {
            prefix += nums[i];//-2 1 

            //Current maximum Subarray_sum in the given array
            maxi = max(maxi,prefix);//-2 1 maxi = 1 at the end not -1.

            if(prefix < 0)
            {
                prefix = 0;//0
            }
        }

        return maxi;

        //TC : O(n)
        //SC : O(n)
        
    }
};