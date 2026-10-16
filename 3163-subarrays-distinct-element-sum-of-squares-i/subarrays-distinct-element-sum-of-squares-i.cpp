class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();

        int counts = 0;

        //Subarray sum => n^2.

        for(int i = 0;i <  n;i++) {

            unordered_set<int>st;

            for(int j = i;j < n;j++) {
                st.insert(nums[j]);
                counts += (st.size()*st.size());
            }
        }

        return counts;


    }
};