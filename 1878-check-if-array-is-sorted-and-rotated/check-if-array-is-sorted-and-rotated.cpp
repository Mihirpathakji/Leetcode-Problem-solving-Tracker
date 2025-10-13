class Solution {
public:
    bool check(vector<int>& nums) {

// Made a sorted vector : sorted_nums
        vector<int>sorted_nums=nums;
        sort(nums.begin(),nums.end());


// sorted_nums contains the sorted array.

        int n =nums.size();
        for(int r=0;r<=n;r++)
        {
            bool is_sorted=true;
            for(int i=0;i<n;i++)
            {
                if(nums[(i+r)%n]!=sorted_nums[i])
                {
                    is_sorted=false;
                    break;
                }
            }
            if(is_sorted==true)
            {
                return true;
            }
        }
        return false;

    }
};