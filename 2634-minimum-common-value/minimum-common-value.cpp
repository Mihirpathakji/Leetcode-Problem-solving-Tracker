class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int l = 0;//on 1st
        int r = 0;//on 2nd

        bool flag = false;
        int min_integer = INT_MAX;
        
        while(l < nums1.size() && r < nums2.size())
        {
            if(nums1[l] == nums2[r])
            {
                flag = true;
                min_integer = nums1[l];
                break; 
            }
            else
            {
                if(nums1[l] < nums2[r])
                {
                    l++;
                }
                else
                {
                    r++;
                }
            }
        }

        if(!flag)
        {
            return -1;
        }

        return min_integer;

        //TC : O(min(nums1,nums2)).
        //sc : o(1).

    }
};