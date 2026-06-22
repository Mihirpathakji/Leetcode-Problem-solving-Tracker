class Solution {
public:

    int index(vector<int>&nums,int target)
    {
        //Count number of elements which are >= target.
       
        int counts = 0;
        for(int i = 0 ; i  < nums.size(); i++)
        {
            if(nums[i] >= target)
            {
                counts++;
            }
        }
        return counts;
    }

    int specialArray(vector<int>& nums) {

        //[0,0,3,4,4].

        int low = 0;
        int high = 1000;

        while(low <= high)
        {
            int mid = low + (high-low);//500
            int values = index(nums,mid);//0
            if(values == mid)
            {
                return values;
            }
            else if(values > mid)
            {
                low = mid +1;
            }
            else
            {
                high = mid -1;
            }
        }
        return -1;

        //TC : O(n*logn)
        //SC : O(1)

    }
};