class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int>nums2;//O(n)
        vector<int>ans;//O(n)
        unordered_map<int,int>mp;//O(n)
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]+=1;
        }
        
        //This stores the frequnecy of all the Numbers :
        
        for(auto it : mp)
        {
            if(it.second==2)
            {
                nums2.insert(it.first);
            }
        }

        for(auto it :nums2)
        {
            ans.push_back(it);
        }
        return ans;

        //TC : O(3*N)
        //SC : O(3*N)
    }
};