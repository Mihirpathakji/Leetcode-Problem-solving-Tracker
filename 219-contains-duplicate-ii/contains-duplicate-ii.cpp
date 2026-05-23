class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        //Check for the duplicates.

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {//i=0 1 2 3 4 5
            if(mp.find(nums[i])!=mp.end())
            {
                if(i - mp[nums[i]] <= k)
                {
                    return true;
                }
            }
            
            mp[nums[i]] = i;//mp[1] = 0  mp[2] =1  mp[3]=2  mp[1]=3  mp[2]=4  mp[3]=5
        }

        return false;
        
    }
};