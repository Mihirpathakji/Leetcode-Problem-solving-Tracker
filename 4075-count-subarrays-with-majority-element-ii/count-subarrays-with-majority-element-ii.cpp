class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int,int>mp;

        mp[0] = 1;

        long long prefix_sum = 0;
        
        long long subarray_counts = 0;
        long long valid_left_points = 0;//varaible to track how many indices are there before index j which satisfies pf[i-1] < pf[j].

        for(int j = 0;  j < n; j++)
        {
            
            if(nums[j] == target)
            {
                valid_left_points += mp[prefix_sum];
                prefix_sum += 1;
            }
            else
            {
                prefix_sum += -1;        
                valid_left_points -= mp[prefix_sum];
            }

            mp[prefix_sum]++;
            subarray_counts += valid_left_points;
        } 

        return subarray_counts;
        
    }
};