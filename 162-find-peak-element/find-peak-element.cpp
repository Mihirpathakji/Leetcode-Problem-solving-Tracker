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
        int low=0;//0
        int high=n-1;//4
        while(low<=high)
        {//0<=4 //0<=1
            int mid=low+(high-low)/2;//2//0 
            if(mid==0)
            {
                return 1;
            }
            if(mid==n-1)
            {
                return n-2;
            }

            //check if nums[mid] is itself the peak element?
            if(mid>0 && mid<n-1 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {//2<4
                return mid;
            }
            //Whether nums[mid] is on an increasing curve ??
            else if(mid >0 && mid <n-1 && nums[mid]<nums[mid+1]  && nums[mid]>nums[mid-1])
            {
                //nums[mid] is on the Left Half of the peak:
                low=mid+1;
            }
            //Whether the nums[mid] is on Decreasing curve??
            else if(mid >0 && mid<n-1 &&  nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1])
            {
                high=mid-1;//high=1
            }
            //only one case remains that nums[mid] is point at the bottom which at peak at it's both sides.
            else if( mid>0 && mid<n-1 && nums[mid]<nums[mid+1]  && nums[mid]<nums[mid-1])
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