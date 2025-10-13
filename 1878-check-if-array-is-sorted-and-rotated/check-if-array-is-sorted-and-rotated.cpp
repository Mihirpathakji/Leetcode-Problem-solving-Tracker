class Solution {
public:
    bool check(vector<int>& nums) {

        //Always remmber the index which is GOING Out of the bounds say Here the index (i+1)  was going out of the bounds there by we do there (index)%n

        // Most optimal solution : 

        int n=nums.size();

        int peak=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                peak++;
            }
        }

        return peak<=1;

       //Tc  : O(n)  && Sc :O(1) 


    }
};