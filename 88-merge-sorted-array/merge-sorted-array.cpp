class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int>nums3(m+n);
        int i = 0;
        int j = 0;
        int index = 0;

        while( i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                nums3[index] = nums1[i];
                i++;//2
                index++;//2
            }
            else
            {
                nums3[index] = nums2[j];
                j++;
                index++;
            }
        }

        if(i == m)
        {
            //no elements remained from nums1[]  there may be elements from nums2[] yet to be filled.
            while(j<n)
            {
                nums3[index] = nums2[j];
                j++;
                index++;
            }
        }
        
        else
        {
            while(i < m)
            {
                nums3[index] = nums1[i];
                i++;
                index++;
            }
        }

        nums1=nums3;

    }
};