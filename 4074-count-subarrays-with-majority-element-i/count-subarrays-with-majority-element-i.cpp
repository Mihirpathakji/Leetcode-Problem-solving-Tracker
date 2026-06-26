class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        //Brute Force :

        int n = nums.size();  
        int subarray_counts = 0;      
        
        for(int i = 0;i < n;i++) {

            if(nums[i] == target) {
                nums[i] = 1;    
            }
            else {
                nums[i] = -1; 
            }
        }   

        for(int i = 1;i < n;i++)
        {
            nums[i] = (nums[i-1]+nums[i]);
        }

        for(int i = 0;i < n;i++)
        {
            for(int j = i;j < n;j++)
            {
                int sum;
               
                if(i > 0) { 
                    sum = nums[j] -nums[i-1];
                }

                else {
                    sum = nums[j];
                }

                if(sum >0) {
                    subarray_counts++;
                }
            }
        }
        
        return subarray_counts;

    }
};