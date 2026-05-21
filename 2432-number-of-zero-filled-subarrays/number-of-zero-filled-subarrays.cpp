class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();

        long long result = 0;
        int consecutive_zero_just_back = 0;

        for(int i = 0 ; i < n;i++)
        {
            if(nums[i] == 0)
            { 
                result += (consecutive_zero_just_back + 1);
                consecutive_zero_just_back++;
            }
            else
            {
                consecutive_zero_just_back = 0;//0
            }
        }
        return result;

    }
};