class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        int ans=INT_MAX;
        //Approach:We will use the Property of the Rotated sorted array:ATLEAST ONE OF THE  porition with respect to the mid must be sorted .Either left of the mid or the right of the mid or may be both.

        //->Key : "Identify" which portion of the nums is "sorted"."Use the property of that portion being sorted i.e  We know in sorted array the minimum value occur at the leftmost index only .Got that minimum value from the sorted part thereby eliminate that sorted part from which you had taken the minimum value .And search for the minimum  value in the another part only .Hence the search space gets reduced "

        while(low<=high)
        {
            mid=low+(high-low)/2;//1//2  3 
            //1.Check if the left portion of the mid is sorted i.e [L,M]
            if(nums[low]<=nums[mid])
            {
                //left part is sorted ->took minimum from that left sorted part [L,M] which will be arr[l]
                ans=min(ans,nums[low]);//11 11 11
                //eliminate that taken(Left) search space->Move to the right .search in another part
                low=mid+1;//2  3  4 
            }
            else
            {
                //Left protion is not sorted than by the property of the "Rotated sorted array"->The Right part will be sorted .
                //get the minimum element of the right part.[M,H]-> arr[Mid] is minimum in right part
                ans=min(ans,nums[mid]);
                //eliminate the taken right search space .i.e Move towards the left
                high=mid-1;
            }
        }
        return ans;

        //TC:O(log2(n))
        //SC:O(1)
    }
};