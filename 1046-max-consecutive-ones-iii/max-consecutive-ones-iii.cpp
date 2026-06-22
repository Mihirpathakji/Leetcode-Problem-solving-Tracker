class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroes_count = 0;
        int max_len = INT_MIN;
        
        while(j < n)
        {
            if(nums[j] == 0)
            {
                zeroes_count++;
            }

            while(zeroes_count > k)
            {
                if(nums[i] == 0)
                {
                    zeroes_count--;
                }
                i++;
            }

            max_len = max(max_len,j-i+1);
            j++;
        }

        return max_len;
    }
};