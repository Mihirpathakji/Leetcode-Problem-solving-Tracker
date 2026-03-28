class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        //st1 = nums1 since the data type on the both sides is different . Hence we cannot assign it like nums1 = nums2;
        //But to take whole vector nums1 inside the segt st1 there is one proper syntax :

        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());

        int answer1 = 0;
        int answer2 = 0;

        for(auto it : nums1)
        {
            if(st2.count(it))
            {
                answer1++;
            }
        }

        for(auto it : nums2)
        {
            if(st1.count(it))
            {
                answer2++;
            }
        }

        return {answer1,answer2};
        
    }
};