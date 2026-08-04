class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int>ans;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int i = 0;i < n;i++) {
            mp[nums[i]] = 1;
        }

        for(int i = 1;i <= 100;i++) {
            if(i < maxi && i > mini) {
                if(mp[i] == 0) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
        
    }
};