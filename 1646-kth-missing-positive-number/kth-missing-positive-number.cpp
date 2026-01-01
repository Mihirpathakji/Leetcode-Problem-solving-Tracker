class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        //Binary search on the indices since the indices have Monotonic nature :
       
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            //Check if Missing element from this index mid is >=k or < k:
            int missing_ele_no = arr[mid] - (mid + 1);
          
            if(missing_ele_no >= k)
            {   
                //There's chances of getting missing element.(>=k)
                ans = mid;// index which can be useful we can obtain the kth missing element//0
                high = mid - 1; 
            }
            else
            {
                //this index cant give you the missing element.
                low = mid + 1;
            }
        }
        if( ans == -1 )
        {
            ans = n;
        }
        return ans + k;

        //TC:O(log(n))
        //SC:O(1)
    }
};