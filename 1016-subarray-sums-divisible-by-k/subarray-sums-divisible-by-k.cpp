class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>prefix_arr(n);
        prefix_arr[0] = arr[0];

        for(int i=1;i<n;i++)
        {
            prefix_arr[i] = prefix_arr[i-1] + arr[i];
        }

       

        unordered_map<int,int>mp;
        mp[0] = 1;
        
        int subarrays = 0;


        for(int j = 0 ;j < n ; j++)
        {
            int rem = prefix_arr[j] % k;

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
        //SC:O(N)
        
    }
};