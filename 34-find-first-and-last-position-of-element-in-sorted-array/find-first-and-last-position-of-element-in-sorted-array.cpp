class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        //First Position of the element can be founded by Doing one Binary Search:
        int low=0;
        int high=n-1;//0-1==-1
        int first_occurance=-1;
        int mid;
        //1.Binary_Search To find the First Occurance (index) of target.
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                //target is present store that index in variable look for the First Occurance of that target.
                first_occurance=mid;
                //Wanted the First Occurance of mid->Move towards the Left side:
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;    
            }
        }
        if(first_occurance ==-1)
        {
            return {-1,-1};            
        }

        //2.Again binary search to find the Last Occurance ( index ) of Target .

        low=0;
        high=n-1;
        int last_occurance=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                last_occurance=mid;
                //Look for the Last Occurance of that element.
                //Move towards Right.
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return {first_occurance,last_occurance};
        //TC:O(log2(n))
        //SC:O(1)
    }
};