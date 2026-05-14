class Solution {
public:
    bool isGood(vector<int>& nums) {

        long long maxi  = *max_element(nums.begin(),nums.end());
        unordered_map<long long,long long>mp;
        for(long long i = 0 ;i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }   

        //1.Maaximum element must appeared twice exactly.

        if(mp[maxi] < 2 || mp[maxi] > 2)
        {
            return false;
        }

        //2. All elements from 1 to maxi-1 elements should be appeared exactly once.    

        for(long long i = 1; i <= maxi-1; i ++)
        {
            if(mp[i] < 1 || (mp[i]>1 && i!=maxi))
            {
                return false;
            }

        }

        return true;
        
    }
};