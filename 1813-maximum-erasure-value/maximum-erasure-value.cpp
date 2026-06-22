class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int j = 0;
        int curr_sum = 0;
        int max_sum= INT_MIN;
  
        unordered_map<int,int>mp;

        while(j < n)
        {
            curr_sum += nums[j];//always.
            mp[nums[j]]++;//always.


            //Invalid window : The Number of uniques elements in subarray are less than it's size i.e  All elements in the subarray are not unique there are duplicates in window.
        
           //Invalid window shrink.

           while(mp.size() < j-i+1)
            {
                curr_sum -= nums[i];
                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i++;
            }

            max_sum = max(max_sum,curr_sum);
            j++;
        }

        return max_sum;

        //tc : O(n)
        //sc : O(1)
        
    }
};