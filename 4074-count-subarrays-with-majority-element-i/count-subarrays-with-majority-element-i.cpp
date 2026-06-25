class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        //Brute Force :

        int n = nums.size();
        int subarray_counts = 0;

        for(int i = 0;i < n;i++)
        {
            unordered_map<int,int>mp;
            for(int j = i;j < n;j++)
            {
                
                if(nums[j] == target)
                {
                    mp[target]++;
                }
                if(mp[target] > (j-i+1)/2)
                {
                    subarray_counts++;
                }
            }
        }
        
        return subarray_counts;

    }
};