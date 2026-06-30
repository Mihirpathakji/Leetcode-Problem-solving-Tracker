class Solution {
public:

    long long maxSum(vector<int>& nums, int k, int mul) {

        sort(nums.rbegin(),nums.rend());//[4,4] 

        long long sum  = 0;

        int break_index = 0;
        int index_cnt = 0;
        for(int i = 0; i < k;i++) {
            
            if(mul == 0) {
                break_index = i;
                break;
            }

            sum += ((long long)mul*nums[i]);//4
            mul--;//0
            index_cnt = i;
        }

        if(index_cnt == k-1) {
            return sum;
        }

        for(int j = break_index;j < nums.size();j++ ) 
        {
            if(j == k) {
                break;
            }
            sum +=nums[j];
        }

        return sum;

    }
};