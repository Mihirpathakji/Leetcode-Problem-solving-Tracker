class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        //Apply binary search on the Remaining search space:
        //1.Try to eliminate the 
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            //Check if this an single element:
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            //condition is if() Just observe it and code it
            if(mid%2==0 && nums[mid]==nums[mid-1]  || mid%2==1 && nums[mid]==nums[mid+1])
            {
                high=mid-1;//3
            }
            else
            {
                low=mid+1;
            }    
        }
        return -1;
        //TC:O(log2(n))
        //SC:O(1)
    }
};