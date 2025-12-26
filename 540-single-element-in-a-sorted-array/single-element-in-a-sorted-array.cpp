class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Brute Force :
        int n=nums.size();//[1]
        for(int i=1;i<n;i++)
        {//i==2
            if(nums[n-1]!=nums[n-2])
            {
                return nums[n-1];
            }
            if(nums[i]!=nums[i+1]  && nums[i]!=nums[i-1])
            {
                return nums[i];
            }
        }
        return nums[0];
        //TC:O(n)
        //SC:O(1)
    }
};