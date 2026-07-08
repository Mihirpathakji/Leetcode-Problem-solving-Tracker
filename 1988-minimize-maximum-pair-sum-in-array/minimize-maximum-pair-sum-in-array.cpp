class Solution {
public:

    int minPairSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int max_Sum = INT_MIN;

        int i = 0;
        int j = n-1;

        while(i < n/2 && j >= n/2) {
            max_Sum = max(max_Sum,nums[i]+nums[j]);
            i++;
            j--;
        }

        return max_Sum;

        //TC : O(nlogn)
        //SC : O(1)

    }
};