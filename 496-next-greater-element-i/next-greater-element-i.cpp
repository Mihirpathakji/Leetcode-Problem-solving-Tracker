class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        int n = nums2.size();
        vector<int>ans(n,-1);

        for(int i = 0 ; i < n; i ++)
        {
            while(!st.empty() && nums2[i] > nums2[st.top()])
            {
                ans[st.top()] = nums2[i];
                st.pop();
            }

            st.push(i);
        }//O(n)
        
        //       0 1 2  3
        //ans = [3 4 -1 -1]

        vector<int>final_ans(nums1.size());

        for(int i = 0 ; i< nums1.size(); i++)
        {
            for(int j = 0; j< nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    final_ans[i] = ans[j];
                    break;
                }
            }
        }

        return final_ans;

    }
};