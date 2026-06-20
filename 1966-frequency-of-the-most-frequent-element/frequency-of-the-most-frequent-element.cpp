class Solution {
public:

    bool ispossible(vector<int>&nums,int k,int target_index,vector<long long>&prefix_sum,long long lower_index)
    {

        long long curr_sum = -1;
        if(lower_index > 0) {
            
            curr_sum = prefix_sum[target_index]-prefix_sum[lower_index-1];
        }
        else {
            curr_sum = prefix_sum[target_index];
        }   

        long long obtained_sum = (target_index-lower_index+1)*nums[target_index];

        return obtained_sum-curr_sum <= k;
    }
   
   
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size(); 
        sort(nums.begin(),nums.end());
        
        vector<long long>prefix_sum(n);
        
        prefix_sum[0] = nums[0];
        
        for(int i = 1; i < n ;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + (long long)nums[i];
        }

        long long max_freq = 1;
        long long low = 0;
        long long high = -1;

        for(int i = 0 ; i< n; i++)
        {   
            low = 0;
            high = i;

            while(low <= high)
            {
                long long mid = low + (high-low)/2;

                if(ispossible(nums,k,i,prefix_sum,mid))
                {
                    max_freq = max((long long)i-mid+1,max_freq);
                    high = mid -1;
                }
                else
                {
                    low = mid + 1;
                }
            } 

        }

        return max_freq;

        
    }
};