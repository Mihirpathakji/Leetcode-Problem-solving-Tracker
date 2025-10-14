class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();
        set<int>st;

        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }// 

        //O(n)  <- will contains all unique + sorted

        // Making the original nums exact same as st:

        nums.assign(st.begin(),st.end());// Sc : O(n)

        return st.size();

        //Tc : O(n)
        //Sc : O(n)

    }
};