class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        long long sum = 0;
        sort(nums.rbegin(),nums.rend());
        int i = 0;

        while(k) {

            sum += (long long)mul*nums[i];
            i++;
            mul--;
            k--;
             
            if(mul == 0) {
                break;
            }
        }

        if(k == 0) {
            return sum;
        }

        while(k) {
            sum += (long long)nums[i];
            i++;
            k--;
        }

        return sum;  

    }
};