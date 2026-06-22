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
        int high = *max_element(nums.begin(),nums.end());

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
                //No.of values >= mid in array are even greater than the mid.i.e your mid is too smaller increment the mid -> increment the low.
                low = mid +1;//
            }
            else
            {
                //No. of values >= mid are even lessser than the mid.i.e your mid is too large decrement the mid -> decrement the high.
                high = mid -1;
            }
        }
        return -1;

        //TC : O(n*logn)
        //SC : O(1)

    }
};