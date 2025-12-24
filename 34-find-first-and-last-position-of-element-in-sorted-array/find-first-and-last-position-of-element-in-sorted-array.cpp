class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //O(n) Good solution:
        int n=nums.size();
        int first=-1;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                if(first==-1)
                {
                    first=i;   
                }
                last=i;
            }
        }
        return {first,last};
    }
    //TC:O(n)
    //SC:O(1)
};