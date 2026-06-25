class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        //Replace all odd values with 1 and all even values with 0.

        unordered_map<int,int>mp;//To store the Oddcount for the odd numbers seen in past.

        for(int i = 0;i  < n;i++)
        {
            if(nums[i]%2 == 1)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        } 

        //Now ans is subarray sum equals k.

        int prefix_sum = 0;
        int counts = 0;

        for(int i = 0;i < n;i++)
        {
            prefix_sum += nums[i];

            //Edge case :

            //If any prefix subarray has oddcount exactly k.

            if(prefix_sum == k)
            {
                counts++;
            }

            if(mp.find(prefix_sum-k)!=mp.end())
            {
                counts += mp[prefix_sum-k];
            }

            mp[prefix_sum]++;
        }

        return counts;

        
    }
};