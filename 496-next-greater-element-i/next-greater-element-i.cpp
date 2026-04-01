class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size(); 
    vector<int>ans(nums2.size());
    stack<int>st;

    unordered_map<int,int>mp;
    for(int i=0;i<nums2.size();i++)
    {
        mp[nums2[i]] = i;//index j of  the nums2.
    }

    for(int j = nums2.size()-1 ; j >= 0 ; j--)
    {
        while(!st.empty() && st.top() <=nums2[j])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[j] = -1;
            st.push(nums2[j]);
        }
        else
        {
            ans[j] = st.top();
            st.push(nums2[j]);
        }
    }       

    vector<int>ans2(nums1.size());
    
    for(int i=0;i<nums1.size();i++)
    {
        if(mp.find(nums1[i])!=mp.end())
        {
            ans2[i] = ans[mp[nums1[i]]]; 
        }
    }
         return ans2;

         //TC:O(N)
         //SC:O(N)
    }
};