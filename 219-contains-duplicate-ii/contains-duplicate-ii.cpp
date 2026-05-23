class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        //Check for the duplicates.

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                if(i - mp[nums[i]] <= k)
                {
                    return true;
                }
            }
            
            mp[nums[i]] = i;//mp[1]=0  mp[2]=1 mp[3] = 2
        }

        return false;
        
    }
};