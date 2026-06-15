class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= first) {
                first = nums[i];//20 10 5 1 1
            }
            else if(nums[i] <= second ) {
                second = nums[i];//100 12
            }
            else {
                return true;//13
            }
        }

        return false;
    }
};