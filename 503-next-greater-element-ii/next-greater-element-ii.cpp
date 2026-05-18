class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        stack<int>st;

        vector<int>ans(n,-1);
        for(int i = 0; i< n;i ++)
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                ans[st.top()] = nums[i];
                st.pop();
            }          
            st.push(i);
        }

        for(int i = 0 ;i < st.top(); i++)
        {   
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                ans[st.top()] = nums[i];
                st.pop();
            }
        }

        return ans;

        //TC : O(n)
        //SC : O(n)
            
    }
};