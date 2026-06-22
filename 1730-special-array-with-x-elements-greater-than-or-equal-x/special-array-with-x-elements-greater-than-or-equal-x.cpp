class Solution {
public:
    int specialArray(vector<int>& nums) {

        //Brute force : O(n^2)

        int n = nums.size();

        for(int x = 0;x <= 1000; x++)
        {
            //calculate the no. of elements >= x in array.

            int counts = 0;
            for(int i = 0; i< n; i++)
            {
                if(nums[i] >= x)
                {
                    counts++;
                }
            }
            if(counts == x)
            {
                return x;
            }
        }
        return -1;
        
    }
};