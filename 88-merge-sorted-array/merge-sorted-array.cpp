class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //Start filling the maximum elements in the nums1 from the back:- This will prevent the Overwriting of the elements.

        int i = m - 1;//2
        int j = n -1;//2
        int index = m + n - 1;//5

        while(j >= 0 && i >= 0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[index] = nums1[i];
                i--;
                index--;
            }
            else
            {
                nums1[index] = nums2[j];
                j--;
                index--;
            }
        }

        if( i < 0)
        {
            //i<0 i.e elements in the nums1 were Grater in the value than the elements in the nums2.
            //place all the elements of the nums2 in the nums1 in backward fashion.
            while(j>=0)
            {
                nums1[index] = nums2[j];
                j--;//-1
                index--;
            }
        }

        //TC:O(n+m)
        //SC:O(1)

    }
};