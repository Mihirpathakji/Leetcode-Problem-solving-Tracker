class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        //Brute Force :

        int n = nums.size();  
        int subarray_counts = 0;

        for(int i = 0;i < n;i++)
        {
            int counts_target = 0;

            for(int j = i;j < n;j++)
            {
                if(nums[j] == target) {
                    counts_target += 1;
                }
                else {
                    counts_target -=1;
                }

                if(counts_target > 0) {
                    subarray_counts++;
                }

            }
        }
        
        return subarray_counts;

    }
};