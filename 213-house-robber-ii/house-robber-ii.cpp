class Solution {
public:


    int rob(vector<int>& nums) {

        //SPACE OPTIMIZATION : 

        int n = nums.size();

        //Base cases : 

        if(n == 1) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0],nums[1]);
        }

        int first = nums[0];//0
        int second = max(nums[0],nums[1]);//1

        int third = second;
        int maxi1 = INT_MIN;

        //1.For 0th to n-2 th index.

        for(int i = 2;i < n-1;i++) {
            third = max(nums[i] + first,second);
            first = second;
            second = third;
        }

        maxi1 = max(maxi1,third);

        first = nums[1];
        second = max(nums[1],nums[2]);

        third = second;

        //For the 1 to n-1 th .

        for(int i = 3;i <= n-1;i++) {
            third = max(nums[i] + first,second);
            first = second;
            second = third;
        }

        maxi1 = max(maxi1,third);

        return maxi1;

        //TC : O(n)
        //SC : O(1)
        
    }
};