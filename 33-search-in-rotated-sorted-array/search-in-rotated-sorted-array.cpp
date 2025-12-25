class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        //Approach :- Here the vector is rotated sorted .So you need to identify which Portion of the vector is sorted??? Thereby apply binary search only on that much sorted portion.i.e Eliminate the remaining search space.  


        while(low<=high)
        {
            mid=low+(high-low)/2;

            if(nums[mid]==target)
            {
                return mid;
            }
            //1.If nums[mid]!=target->This is an Rotated sorted Array You need to check Which portion is sorted.Whether the Left portion is sorted or right?
            //Is Left Portion sorted??
            else if(nums[low]<=nums[mid])
            {
                //Yes.
                //Is my element lying on left sorted part?
                if(nums[low]<=target && target<nums[mid])
                {
                    //Yes.
                    //search only on that "left" part.
                    high=mid-1;
                }
                else
                {
                    //Left portion sorted but element not on left part->Search on right part:
                    low=mid+1;
                }
            }
            else
            {
                //Left portion is "not" sorted ->Right Portion "must be" sorted
                //Okay then check if my target lying on right part or not!
                if(nums[mid]<target && target<=nums[high])
                {
                    //Yes.
                    //Search only on right part ."Eliminate the Left search space"
                    low=mid+1;
                }
                else
                {
                    //right part sorted but target not on right part .
                    //i.e search on the left part only .Eliminate the right search space.
                    high=mid-1;
                }
            }
        }
            return -1;
            //TC:O(log2(n))
            //SC:O(1)
    }
};