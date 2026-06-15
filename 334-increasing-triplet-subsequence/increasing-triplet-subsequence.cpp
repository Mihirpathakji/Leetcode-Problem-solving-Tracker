class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int first_min = INT_MAX;
        int second_min = INT_MAX;

        //Greedy:

        for(int i = 0 ; i< n; i++)
        {
            if(nums[i] < first_min)
            {
                first_min = nums[i];//0
            }
            else if(nums[i] < second_min && nums[i] > first_min)
            {
                second_min = nums[i];//0
            }
            else
            {   
                if(nums[i] > first_min && nums[i] >second_min )
                return true;
            }
        }
        
        return false;

    }
};