class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        int n = nums2.size();
        vector<int>ans(n,-1);

        //We will use a hashmap to keep Track of index also.

        unordered_map<int,int>mp_nums2;

        for(int i = 0 ; i < n; i++)
        {
            mp_nums2[nums2[i]] = i;
        }

        for(int i = 0 ; i < n; i ++)
        {
            while(!st.empty() && nums2[i] > nums2[st.top()])
            {
                ans[st.top()] = nums2[i];
                st.pop();
            }

            st.push(i);
        }//O(nums2.size())
        
        //       0 1 2  3
        //ans = [3 4 -1 -1].

        vector<int>final_ans(nums1.size());

        for(int i = 0 ; i < nums1.size(); i++)
        {
            if(mp_nums2.find(nums1[i])!=mp_nums2.end())
            {
                int index = mp_nums2[nums1[i]];
                final_ans[i] = ans[index];
            }
        }//O(nums1.size())   

        return final_ans;

        //TC : O(n + m)
        //SC : O(n + m)

    }
};