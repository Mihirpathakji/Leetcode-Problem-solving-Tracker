class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long long n = nums.size();
        long long prefix_product = 1;
        long long suffix_product = 1;

        long long max_product = INT_MIN;

        for(long long i = 0; i < n ; i++)
        {
            prefix_product *= nums[i];
            suffix_product *= nums[n-i-1];

            max_product = max(max_product,max(prefix_product,suffix_product));

            if(prefix_product == 0)
            {
                prefix_product = 1;//i.e New subarray from prefix side will start.
            }

            else if(suffix_product == 0)
            {
                suffix_product =1;//i.e New subarray from suffix side will start.
            }

        }

        return max_product;

        //TC : O(n)
        //SC : O(1)   
    }
};