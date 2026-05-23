class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int>original = nums;
        sort(original.begin(),original.end());
        vector<int>nums2 = nums;

        int k = nums.size();//

        while(k)
        {
            
            for(int i =0; i < nums.size(); i++)
            {
                nums2[(i+1)%nums2.size()] = nums[i];
            }
            
            if(nums2 == original)
            {
                return true;
            }
            k--;
            nums=nums2;
            
        }

        return false;

    }
};