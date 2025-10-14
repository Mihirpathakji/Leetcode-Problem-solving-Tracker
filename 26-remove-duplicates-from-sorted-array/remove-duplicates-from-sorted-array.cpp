class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        //Most optimal approach :

        int n=nums.size(); //O(1)
        int j=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[j]=nums[i];
                j++;
            }
        }

        return j;

        //Tc : O(n)

        //Sc : O(1)
        
    }
};