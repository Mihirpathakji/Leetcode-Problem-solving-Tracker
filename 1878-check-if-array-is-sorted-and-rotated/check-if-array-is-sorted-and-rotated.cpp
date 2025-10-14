class Solution {
public:
    bool check(vector<int>& nums) {
        
        // Most optimal one solution for this problem : Tc : O(n)

        // We will iterate through it till the Last element and check if the dip/Peak  occurs for only one time then it is correct Then it can be 

        int n=nums.size(); 
        int dip=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[(i+1)])
            {
                // there is one downfall founded.
                dip++; 
            }
        
        }
        if(nums[n-1]>nums[0])
        {
            dip++;
        }


        return dip<=1; 


    }
};