class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();

        vector<int>nums2;

        nums2.push_back(nums[0]);
        
        for(int i=0;i<n-1;i++)
        {   
            if(nums[i]!=nums[i+1])
            {
                nums2.push_back(nums[i+1]);
            }
        }

        nums=nums2;

        return nums2.size();

    //Tc : O(n)

    //Sc : O(n)

    }
};