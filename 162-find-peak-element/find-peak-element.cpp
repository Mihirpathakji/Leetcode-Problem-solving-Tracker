class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {//[1]
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        //I had already checked for i==0 and i==n-1 .Now If the answer were at those indices then it could have been returned.Now ,If it not at those indices than why to include those indices in my search space when i already know muy answer is not the index=0 or index =n-1;Then i would not include them in my search space.  

        // We had already covered if i==0 i==n-1 gives answer.Now if it dosent gives us the answer better is EXCLUDE them from our search space .Hence took low=1 AND high=n-2 mid will never be 0 and never be n-1 by this search space.
        int low=1;//0
        int high=n-2;//4

        //Appraoch:nums[mid] can have only 4 possibilities with respect to peak element.Our target is to get that peak element. 


        while(low<=high)
        {//0<=4 //0<=1
            int mid=low+(high-low)/2;//2//0 


            //check if nums[mid] is itself the peak element?
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {//2<4
                return mid;
            }
            //Whether nums[mid] is on an increasing curve ??
            else if(nums[mid]<nums[mid+1]  && nums[mid]>nums[mid-1])
            {
                //nums[mid] is on the Left Half of the peak:
                low=mid+1;
            }
            //Whether the nums[mid] is on Decreasing curve??
            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1])
            {
                high=mid-1;//high=1
            }
            //only one case remains that nums[mid] is point at the bottom which at peak at it's both sides.
            else if(nums[mid]<nums[mid+1]  && nums[mid]<nums[mid-1])
            {
                //is either of the side you can find an peak element.Go to any of the side 
                low=mid+1;
            }
            //TC:O(log2(n))
            //SC:O(1)
        }
        return -1;
    }
};