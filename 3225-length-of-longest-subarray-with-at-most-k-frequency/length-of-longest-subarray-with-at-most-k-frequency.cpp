class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int j = 0;

        int max_freq = INT_MIN;//What is the Maximum frequency of any element in my subarray.

        unordered_map<int,int>mp;

        int max_len = INT_MIN;

        while(j  < n)
        {
        
            mp[nums[j]]++;//1 3

            while(mp[nums[j]] > k)
            {
                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }

                i++;
            }

            max_len = max(max_len,j-i+1);

            j++;

        }

        return max_len;

    }
};