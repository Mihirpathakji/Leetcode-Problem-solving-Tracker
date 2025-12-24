class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=n;
        bool flag=false;
        bool slag=false;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                slag=true;
                index=i+1;//4
                break;
            }
        }

        //1.Binary search on left part:
        int low=0;
        int high=index-1;//3
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                flag=true;
                return mid;
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
        if(flag==false && slag==false)
        return -1;

        low=index;//i+1
        high=n-1;//0
        while(low<=high)
        {
            mid=low+(high-low)/2;//0//-1
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;//0-1==-1
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