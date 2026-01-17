class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        //Brute force:
        vector<int>nums3(m+n);
        int i     = 0;
        int j     = 0;
        int index = 0;

        if(n == 0)
        {
            return;
        }

        while(i < m  && j<n)
        {
            if(nums1[i] <= nums2[j])
            {
                nums3[index] = nums1[i];
                index++;//1 2 4
                i++;//1 2 3
            }
            else
            {
                nums3[index] = nums2[j];   
                j++;//1
                index++;//1
            }
        }

        if(j == n)
        {
            while(i < m)
            {
                nums3[index] = nums1[i];
                i++;
                index++;
            }
        }
        else
        {
            //i == m
            while(j < n)
            {
                nums3[index] = nums2[j];
                j++;
                index++;
            }
        }

        nums1=nums3;

    }
};