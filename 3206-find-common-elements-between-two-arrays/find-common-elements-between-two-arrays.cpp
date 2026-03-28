
class Solution {
public:

    bool find(vector<int>nums,int it)
    {
        for(int i = 0 ;i  <nums.size(); i++)
        {
            if(nums[i] == it)
            {
                return true;
            }   
        }
        return false;
    }

    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        int answer1 = 0;
        int answer2 = 0;

        for(auto it : nums1)
        {
            if(find(nums2,it))
            {
                answer1++;
            }
        }

        for(auto it : nums2)
        {
            if(find(nums1,it))
            {
                answer2++;
            }   
        }   
                 
        return {answer1,answer2};

        //TC : O(n*m)

        //SC : O(1)
        
    }
};