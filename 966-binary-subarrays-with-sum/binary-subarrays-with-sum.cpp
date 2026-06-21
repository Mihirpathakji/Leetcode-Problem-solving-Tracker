class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        //No. of Subarray with sum equals k : Prefix sum + Hashmap.
        
        int n = nums.size();
        int prefix_sum = 0;
        int counts = 0;

        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++)
        {
            prefix_sum += nums[i];
            if(prefix_sum == goal)
            {
                counts++;
            }

            if(mp.find(prefix_sum-goal)!=mp.end())
            {
                counts +=mp[prefix_sum-goal];
            }

            mp[prefix_sum]++;
        }

        return counts;

        //TC : O(n)
        //SC : O(n)
        
    }
};