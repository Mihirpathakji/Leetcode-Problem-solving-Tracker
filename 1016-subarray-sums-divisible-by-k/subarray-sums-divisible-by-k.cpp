class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        int n = arr.size();

        int subarrays =0;

        unordered_map<int,int>mp;// stores remainder of the prefix_sums and there frequency. 
        mp[0] = 1;

        //Check if the remainder of prefixsum and the k is before hand in the map or not.

        int prefix_sum = 0;

        for(int i=0;i<n;i++)
        {
            prefix_sum += arr[i];
         
            int rem  = prefix_sum %k;

            if(rem < 0)
            {
                rem = rem + k;
            }

            if(mp.find(rem)!=mp.end())
            {
                subarrays += mp[rem];
            }

            mp[rem]++;

        }

        return subarrays;
        //TC:O(N)
        //SC:O(1)
        
    }
};