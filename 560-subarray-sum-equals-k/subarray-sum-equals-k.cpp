class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        int n = nums.size();
        int count=0;
        vector<int>Prefix_sum(n,0);
        Prefix_sum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            Prefix_sum[i] = Prefix_sum[i-1] + nums[i];
        } 

        unordered_map<int,int>mp;
        
        for(int j=0;j<n;j++)
        {
            //Case 1:
            if(Prefix_sum[j] == k)
            {
                count++;
            }   

            int value  = Prefix_sum[j] - k;

            if(mp.find(value)!=mp.end())
            {
                count += mp[value];
            }
            mp[Prefix_sum[j]]++;
        }
        return count;


    }
};
