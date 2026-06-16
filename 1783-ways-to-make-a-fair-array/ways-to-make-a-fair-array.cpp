class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        int n = nums.size();
        int counts = 0;

        vector<int>odd_prefixsum(n,0);
        vector<int>even_prefixsum(n,0);
        even_prefixsum[0] = nums[0];//0th index is even.
        odd_prefixsum[0] = 0;//0th index is not even.

        for(int i = 1; i < n; i++)
        {
            odd_prefixsum[i] = odd_prefixsum[i-1];//if i is even.->carry forward the old value to ahead.
            even_prefixsum[i] = even_prefixsum[i-1];//if i is odd.->carry forward the old value ahead.

            if(i%2 == 0)
            {
                even_prefixsum[i] += nums[i]; 
            }
            else
            {
                odd_prefixsum[i] += nums[i];
            }
        }

        //Brute force : Remove every possible indexes.

        for(int i = 0; i < n;i++)
        {
            if(i == 0)
            {
                int new_even_sum = even_prefixsum[n-1] - even_prefixsum[0];
                int new_odd_sum = odd_prefixsum[n-1] - odd_prefixsum[0];

                //Check if the new even sum and even odd sum are same or not.

                if(new_even_sum == new_odd_sum)
                {
                    counts++;
                }

            }
            else
            {
                int new_even_sum = even_prefixsum[i-1] + (odd_prefixsum[n-1] - odd_prefixsum[i]);

                int new_odd_sum = odd_prefixsum[i-1] + (even_prefixsum[n-1]-even_prefixsum[i]);

                //Check if both are equal.

                if(new_even_sum == new_odd_sum)
                {
                    counts++;
                }

            }
        }

        return counts;

        //TC : O(n)
        //SC : O(n)
        
    }
};