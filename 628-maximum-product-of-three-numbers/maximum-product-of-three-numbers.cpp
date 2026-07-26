class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());
        int p1 = nums[n-1]*nums[n-2]*nums[n-3];
        
        //Try takig first two negatives.Their product may paid higher.
        int p2 = nums[0]*nums[1]*nums[n-1];

        return max(p1,p2);

        //TC : O(n*logn)
        //SC : O(1)
        
    }
};