class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        long long sum = 0;
        sort(nums.rbegin(),nums.rend());
        int i = 0;

        //[9 6 2 1]

        while(k) {

            sum += (long long)mul*nums[i];//18 24
            i++;//1 2
            mul--;//1 0.
            k--;//1 
             
            if(mul == 0) {
                break;
            }
        }

        if(k == 0) {
            return sum;
        }

        while(k) {
            sum += (long long)nums[i];
            i++;//3
            k--;//0
        }

        return sum;  

    }
};