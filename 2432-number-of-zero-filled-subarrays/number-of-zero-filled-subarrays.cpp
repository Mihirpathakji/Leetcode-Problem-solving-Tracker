class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long n = nums.size();
        
        long long result = 0;
        long long consecutive_zeroes_back = 0;

        for(int i =0 ; i <n; i++)
        {
            if(nums[i] == 0)
            {
                result += (consecutive_zeroes_back + 1);
                consecutive_zeroes_back++;
            }
            else
            {
                consecutive_zeroes_back = 0;
            }
        }

        return result;
        //TC : O(n)
        //SC : O(1)


    }
};