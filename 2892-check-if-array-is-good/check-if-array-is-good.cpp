class Solution {
public:
    bool isGood(vector<int>& nums) {

        //n -> Maximum element of array.

        long long nums_size = nums.size();
        long long maxi = *max_element(nums.begin(),nums.end());

        //1.
        if(nums_size != maxi + 1)
        {
            return false;
        }

        unordered_map<int,int>mp;

        for(int i = 0 ;i < nums_size; i++)
        {
            mp[nums[i]]++;
        }

        //2.
        if(mp[maxi]!=2)
        {
            return false;
        }

        //3.
        for(int i = 1; i <= maxi-1; i++)
        {
            if(mp[i]!=1)
            {
                return false;
            }
        }

        return true;

    }
};