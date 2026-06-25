class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int j = 0;

        int max_freq = INT_MIN;//What is the Maximum frequency of any element in my subarray.

        //There will Never exists more than 2 element with same MAX FREQUNECY > K.BCZ, Movement i find a invalid window with > k i removed elements and thereby every window will have only ONE ELEMENT AT WORST WITH FREQ > K


        unordered_map<int,int>mp;

        int max_len = INT_MIN;

        while(j  < n)
        {
        
            mp[nums[j]]++;
            max_freq = max(max_freq,mp[nums[j]]);

            while(max_freq > k)
            {
                
                if(mp[nums[i]] == max_freq)
                {
                    max_freq--;
                }

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