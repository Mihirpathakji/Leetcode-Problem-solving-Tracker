class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        int total_sum=n*(n+1)/2;
        int nums_sum=0;
        for(int i=0;i<n;i++)
        {
            nums_sum+=nums[i];
        }
        int Missing_number=total_sum-nums_sum;
        return Missing_number;

        return 0;


        // TC : O(n)
        // SC : O(1)

        //Is most opitmal soln
    }
};