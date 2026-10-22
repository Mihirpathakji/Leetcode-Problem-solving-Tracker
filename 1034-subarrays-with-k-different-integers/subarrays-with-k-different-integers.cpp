class Solution {
public:

    int no_subarrays(int num,vector<int>&nums) {
    
        int k = num;
        int n = nums.size();

        //No. of subarrays with atmost k distinct elements.

        int i = 0;
        int j = 0;
        int counts = 0;

        unordered_map<int,int>mp;

        while(i < n && j < n) {

            mp[nums[j]]++;

            while(mp.size()  > k) {

                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i++;
            }
            
            if(mp.size() <= k ) {
                counts += (j-i+1);
            }

            j++;

        }

        return counts;

    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n = nums.size();

        return no_subarrays(k,nums) - no_subarrays(k-1,nums);
        
    }
};