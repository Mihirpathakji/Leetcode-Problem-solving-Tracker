class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {


        int n = nums.size();

        int i = 0;
        int j = 0;

        long double product = 1;
        long long counts = 0;

        while(j < n)
        {
            product *= nums[j];//50 100


            //If the product is invalid i.e product >= k
            while(product >= k && i < j)
            {
                product /= nums[i];//
                i++;
            }

            if(i == j)
            {
                if(nums[j] < k)
                {
                    counts++;
                }
            }

            else
            {
                counts += (j-i+1);
            }

            j++;//1 2

        }

        return counts;

    }
};