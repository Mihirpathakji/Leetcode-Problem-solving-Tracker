class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
           long long n = nums.size();
           long long count=0;
           vector<long long> Prefix_sum(n,0);

           Prefix_sum[0] = nums[0];
           
           for(int i=1;i<n;i++)
           {
                Prefix_sum[i] = Prefix_sum[i-1] + nums[i];
           } 

           //<Prefix_sum,Frequency_of_that_prefix_sum>
           
           unordered_map<long long ,long long> mp;

           for(long long j = 0; j < n ; j ++)
           {    
                //Case 1:
                //Prefix arr's  sum is itself  == k.
                if(Prefix_sum[j] == k)
                {
                    count++;
                }

                //Case 2 :
                //Any segment sum where segment is "not a prefix arr" has sum == k.
                //Finding number of such segments: 
                long long value = Prefix_sum[j] - k;
                if(mp.find(value) != mp.end())
                {
                    count += mp[value];
                }

                mp[Prefix_sum[j]]++;

           }
            return count;
            //TC:O(n)//.find() and insertion occurs in O(1) in an unordered_map.
            //SC:O(n)//mp,Prefix_sum arr

    }
};