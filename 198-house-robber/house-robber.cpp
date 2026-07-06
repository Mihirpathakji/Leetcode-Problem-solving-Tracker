class Solution {
public:

    int rob(vector<int>& nums) {

        //Space Optimization :

        int n = nums.size();
        
        if(n == 1) {
            return nums[0];
        }

        int first = nums[0];
        int second = max(nums[0],nums[1]);

        int third = second;

        for(int i = 2;i < n;i++) {
            third = max(nums[i] + first , second);
            first = second;
            second = third; 
        }

        return third;//Max money obtained by robbing from 0th till n-1 houses.

        //TC : O(n)
        //SC : O(1)

    }
};