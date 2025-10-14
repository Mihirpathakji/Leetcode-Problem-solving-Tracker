class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();// O(1)
        set<int>st;

        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);// O(logn)
        }
        
        // O(nlogn)

        nums.assign(st.begin(),st.end());// -> Tc of O(n)  Sc : O(n)
       
        //  O(n)  

        return st.size();


    //TC : O(nlogn)+O(n)==O(nlogn) 

    //Sc : O(n)


    }
};