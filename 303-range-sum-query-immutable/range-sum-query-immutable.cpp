class NumArray {
public:

    vector<int>prefix1;
    
    NumArray(vector<int>& nums) {

        vector<int>prefix(nums.size());
        prefix[0] = nums[0];//[-2 ]
        for(int i = 1 ;i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        prefix1 = prefix;//[-2 -2 1 -4 -2 -3]//Made it Accessible to the downwards also.

        //O(n) -> One time.
    }
    
    int sumRange(int left, int right) {
        
        if(left == 0)
        {   
            return prefix1[right];
        }

        return prefix1[right]-prefix1[left-1];

        //TC : O(n)
        //SC : O(n)

    }
};