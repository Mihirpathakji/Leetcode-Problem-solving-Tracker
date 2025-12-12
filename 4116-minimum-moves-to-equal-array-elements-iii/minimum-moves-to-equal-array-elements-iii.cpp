class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n;i++)
        {
            //i==0;1
            while(nums[i]!=maxi)
            {
                ops++;//12
                nums[i]++;//55
            }
        }
        return ops;
    }
};