class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        //1.Sorted -> Two Pointer -> l = 0 and r = n-1;->Everything is random at two pointers.

        //2.Sorted -> Sliding window not applicable mostly.

        int n = nums.size();
        int l = 0;
        int r = n-1;

        vector<int>ans;

        while(l < r)
        {
            //Case1 :
            if(abs(nums[l]) > abs(nums[r]))
            {
                ans.push_back(nums[l]*nums[l]);
                l++;
            }

            //Case2 : 
            else if(abs(nums[l]) == abs(nums[r]))
            {
                ans.push_back(nums[l]*nums[l]);
                l++;
            }

            //Case3 : 
            else
            {
                ans.push_back(nums[r]*nums[r]);
                r--;
            }
        }   

        //nums[l] == nums[r] -> Smallest absolute value.
       
        ans.push_back(nums[l]*nums[l]);

        reverse(ans.begin(),ans.end());

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};