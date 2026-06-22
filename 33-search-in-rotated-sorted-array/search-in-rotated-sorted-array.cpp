class Solution {
public:
    int search(vector<int>& nums, int target) {
            
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            //In rotated sorted array : 
            //1.It is fixed that one half will be sorted and another will not be sorted from [low,mid] & [mid,high].

            //We cannot blindly eliminate one search space completely.We need to identify that which half is sorted.thereby searching would be optimal.


            //Identify which half is sorted.After jumping into mid index.

            //1.First part.[low,mid].

            if(nums[low] <= nums[mid])
            {
                //left part is sorted.Check if our x can exists in this range.

                if(nums[low] <= target && target <= nums[mid])
                {
                    //x is on left half search on left half.
                    high = mid -1;
                }
                else
                {
                    //left half is sorted.but our x is not in the left half.Search on right half.
                    low = mid +1;
                }
            }
           
            else
            {
                //If the left part is not sorted.Than it is sure than in a rotated sorted array, if left part is not sorted than the right part will be sorted.

                //Check if our target lies on right half.[mid,high].

                if(nums[mid] <= target && target <= nums[high])
                {
                    //x is on right half .Searh on right half.

                    low = mid + 1;                      
                }
                else
                {
                    //x is not in right half.Search on left half.

                    high = mid - 1;
                }

            }
        }

        return -1;

    }
};