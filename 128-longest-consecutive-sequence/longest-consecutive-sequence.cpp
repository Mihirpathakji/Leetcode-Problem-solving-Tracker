class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //Brute force:

        sort(nums.begin(),nums.end());
        //Remove Duplicates since they dosent impact.

        int n = nums.size();
        int i = 0;
        int j = 1;
        
        if(n == 0) {
            return 0;
        }

        int max_len = 0;
        int curr_len = 1;

        while(j < n) {


            if(!(nums[j] == nums[j-1] + 1 || nums[j] == nums[j-1])) {
                i = j;
                curr_len = 1;
            }
            
            else if( nums[j] == nums[j-1] + 1) {

                curr_len++;
                max_len = max(max_len,curr_len);
            }

            j++;//2 
    
        }

        max_len = max(max_len,curr_len);

        return max_len;
        
    }
};