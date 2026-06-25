class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;//To store the Oddcount for the odd numbers seen in past.

        int prefix_Odd_count = 0;
        int counts = 0;

        for(int i = 0;i < n;i++)
        {   
            if(nums[i] % 2 == 1) {
                prefix_Odd_count ++;
            }

            //Edge case :

            //If any prefix subarray has oddcount exactly k.

            if(prefix_Odd_count == k)
            {
                counts++;
            }

            if(mp.find(prefix_Odd_count-k)!=mp.end())
            {
                counts += mp[prefix_Odd_count-k];
            }

            mp[prefix_Odd_count]++;
            
        }

        return counts;

        //TC : O(n)
        //SC : O(n)

        
    }
};