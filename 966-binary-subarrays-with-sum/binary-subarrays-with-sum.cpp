class Solution {
public:

//This func gives no. of subarrays with sum <= goal.

    int subarrays(vector<int> nums, int goal)
    {

        if(goal == -1)
        {
            return 0;
        }

        int n = nums.size();
        int i = 0;
        int j = 0;

        long long int prefix_sum = 0;
        long long int counts = 0;

        while(j < n)
        {
            prefix_sum += nums[j];//1 2 2 3 //1 2 1 2 //0

            while(prefix_sum > goal)
            {
                prefix_sum -= nums[i];//1 2 2 3-=1 == 2 1 1//0
                i++;//1 2 3 //1 2
            }

            counts += (j-i+1);//1 2 3 4 5    // 6 4 4 == 14 // 1 2 2 3 2

            j++;//1 2 3 4 5 // 1 2 3 4 5
        }

        return counts;

    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {

        //Using sliding window , calculating the number of subarrays with sum <= k is possible.But exactly k is not possible.So, We will calculate the number of subarrays having sum exactly k as (no. of subarrays with sum <=k ) - (no. of subarrays with sum <= (k-1) ).

        //This functions calculate the number of subarrays sum <= x.

        int k = goal;
        return subarrays(nums,k) - subarrays(nums,k-1);

    }
};