class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        int i = m;//

        int j = 0;// 
        while(n--)
        {//n->
            nums1[i]=nums2[j];//
            j++;//
            i++;//
        }
        sort(nums1.begin(),nums1.end());
        //TC:O(log(m+n))
        //SC:O(1)
    }
};