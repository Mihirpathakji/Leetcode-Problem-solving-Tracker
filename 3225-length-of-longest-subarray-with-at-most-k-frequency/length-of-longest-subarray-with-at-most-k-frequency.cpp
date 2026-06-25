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
        
            mp[nums[j]]++;//2 
            max_freq = max(max_freq,mp[nums[j]]);//1 2 2 2 

            while(max_freq > k)
            {
                
                if(mp[nums[i]] == max_freq)
                {
                    max_freq--;//1.But may possible that there exists one more element with the same max_freq.Than we didnt remove it.But we have to remove it.//1 1
                }

                mp[nums[i]]--;//1 
              
                if(mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }    
                
                i++;
            }

            max_len = max(max_len,j-i+1);// 1 2 2 2

            j++;// 1 2 3 4 
        }

        return max_len;

    }
};