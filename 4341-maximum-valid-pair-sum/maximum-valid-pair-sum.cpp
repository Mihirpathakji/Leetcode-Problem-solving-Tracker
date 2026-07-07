class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        int n = nums.size();
        int maxi_track = INT_MIN;

        for(int i = n-1;i >0 ;i--) {
            maxi_track = max(maxi_track,nums[i]);
            mp[i] = maxi_track;
        }   

        long long max_ans = 1;
        for(int i = 0;i <= n-1-k;i++) {
            max_ans = max(max_ans,(long long)mp[i+k]+nums[i]);
        }

        return max_ans;
        
        //TC : O(n)
        //SC : O(n)
    }
};