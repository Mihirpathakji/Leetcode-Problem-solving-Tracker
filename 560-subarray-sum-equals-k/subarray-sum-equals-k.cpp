class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long>prefix_arr(n);
        
        prefix_arr[0] =  nums[0];

        for(int i = 1;i < n;i++)
        {
            prefix_arr[i] = nums[i] + prefix_arr[i-1];
        }

        long long subarr = 0;
        
        unordered_map<int,int>mp;

        mp[0] = 1;
        
        for(int j = 0; j < n ; j++)
        {
            int value = prefix_arr[j] - k;
            
            if(mp.find(value)!=mp.end())
            {
                subarr += mp[value];
            }

            mp[prefix_arr[j]]++;
        }

        return subarr;


        //TC:O(n)

        //SC:O(n)
    }   
};