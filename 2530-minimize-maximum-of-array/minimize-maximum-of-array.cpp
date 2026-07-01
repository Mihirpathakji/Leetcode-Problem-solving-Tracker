class Solution {
public:

    bool isValidMax(long long expected_max,vector<long long> nums) {

        int n = nums.size();
        for(int i = 0;i < n;i++) {

            if(i == n-1) {
                if(nums[i] > expected_max) {
                    return false;
                }
                else {
                    break;
                }
            }
            else {

                if(nums[i] > expected_max) {
                    return false;
                }

                long long buffer = expected_max - nums[i];
                nums[i+1] = nums[i+1] - buffer;
            }
        }

        return true;

    }

    int minimizeArrayValue(vector<int>& nums) {

        //I am Binary searching on the range of valid Max values after applying any number of operations.

        int n = nums.size();
        long long low = 0;//0
        long long high = *max_element(nums.begin(),nums.end());//7
        long long ans = -1;
        vector<long long> arr(nums.begin(),nums.end());

        while(low <= high) {
            
            long long mid = low + (high-low)/2;//expected max.//3

            if(isValidMax(mid,arr)) {
                ans = mid;//expected max.
                high = mid -1; //Minimizing it.
            }
            else {
                low = mid + 1;
            }
        }

        return ans;

        //TC : O(n*log1e9)
        //SC : O(1)


    }
};