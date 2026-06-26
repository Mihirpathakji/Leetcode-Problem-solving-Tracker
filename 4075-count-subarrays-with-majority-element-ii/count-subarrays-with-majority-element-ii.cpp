class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int,int>mp;

        mp[0] = 1;
        long long prefix_sum = 0;
        long long subarray_counts = 0;
        long long valid_left_points = 0;

        for(int j = 0;  j < n; j++)
        {

            if(nums[j] == target)
            {
                valid_left_points += mp[prefix_sum];
                prefix_sum ++;
            }
            else
            {
                prefix_sum--;
                valid_left_points -= mp[prefix_sum];
            }

            mp[prefix_sum]++;
            subarray_counts += valid_left_points;
        } 

        return subarray_counts;
        
    }
};