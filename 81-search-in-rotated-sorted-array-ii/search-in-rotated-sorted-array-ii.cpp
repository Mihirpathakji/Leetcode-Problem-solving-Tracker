class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=-1;
        //Approach : Rotated sorted Array Hence,you need to identify that which portion of the vector is sorted
        while(low<=high)
        {
            mid=low+(high-low)/2;//target

            //
            if(nums[low]==nums[high] && nums[low]!=target)
            {
                low++;
                high--;
                continue;
            }
            if(nums[mid]==target)
            {
                return true;
            }
            //Is left portion sorted?
            else if(nums[low]<=nums[mid])
            {   //Yes
                //Is my target even on the Left part or not ?
                if(nums[low]<=target && target<nums[mid])
                {
                    //Yes target lies on left part.
                    //Search space should be only on the left part.
                     high=mid-1;
                }
                else
                {
                    //left part is sorted but the element is not on the left part.
                    //search it on the right part->
                    low=mid+1;
                }
            }
            else
            {
                //right part must be sorted.
                //check if the target lies On the right part ? or not
                if(nums[mid]<target && target<=nums[high])
                {
                   //Yes.search space should be only right part.
                   low=mid+1; 
                }
                else
                {
                    //right part sorted but the element is not the right part.Search it only on the Left Part
                    high=mid-1;  
                }
            }
        }
            return false;
        //TC:O(Log2(n))
        //SC:O(1)
    }
};