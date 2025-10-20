class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=1;
        }    

        for(int i=0;i<nums2.size();i++)
        {
            if(mp[nums2[i]])
            {
                ans.insert(nums2[i]);
            }
        }
        vector<int>nums3;
        for(auto it:ans)
        {
            nums3.push_back(it);
        }

        return nums3;

        //TC : O(nlogn)
        //SC : O(3*n)

    }
};