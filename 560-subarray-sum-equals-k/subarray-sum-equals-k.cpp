class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        long long n = nums.size();
        long long sum;
        long long c=0;

        for(int i=0;i<n;i++)
        {
            sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                if(sum == k)
                {
                    c++;
                }
            }
        }
        return c;
    }

};