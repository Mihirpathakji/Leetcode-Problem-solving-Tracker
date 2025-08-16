class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            // First Occurence =lower_bound()
            int result=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            // Last Occurence = upper_bound()-1
            int result1=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1; 
            return {result,result1};
        }
            return {-1,-1};
    }
};