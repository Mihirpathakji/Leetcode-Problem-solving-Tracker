class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int prev_max = 0,ans = 0;

        for(int i = k;i < n;i++) {
            prev_max = max(prev_max,nums[i-k]);
            ans = max(ans,nums[i] + prev_max);
        }

        return ans;

        //TC : O(n)
        //SC : O(1)
        
    }
};