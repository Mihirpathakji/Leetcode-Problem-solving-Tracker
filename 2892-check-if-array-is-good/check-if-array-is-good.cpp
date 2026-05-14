class Solution {
public:
    bool isGood(vector<int>& nums) {

        //Max -> twice.
        //all other -> once. 


        long long maxi  = *max_element(nums.begin(),nums.end());
        unordered_map<long long,long long>mp;
        for(long long i = 0 ;i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }   

        if(mp[maxi] < 2 || mp[maxi] > 2)
        {
            return false;
        }

        //1 to maxi-1 elements should be exactly once.    

        for(long long i = 1; i <= maxi-1; i ++)
        {
            if(mp[i] < 1)
            {
                return false;
            }

            else if(mp[i] >= 2 && i!=maxi)
            {
                return false;
            }
        }

        return true;
        
    }
};