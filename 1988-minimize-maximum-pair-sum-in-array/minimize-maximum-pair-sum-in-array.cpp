class Solution {
public:

    int minPairSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());//[2 3 3 5]

        vector<int>nums2(nums.begin(),nums.end());//[2 3 3 5]

        sort(nums2.rbegin(),nums2.rend());//[5 3 3 2]
        
        int min_Sum = INT_MIN;

        for(int i = 0;i < nums.size();i++) {
            min_Sum = max( (nums[i] + nums2[i]) ,min_Sum );
          }

        return min_Sum;

    }
};