class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        //Brute force :

        int n = nums.size();
        vector<vector<int>>ans;

        //2^n times.
        for(int i = 0 ;i < (1 << n); i++)
        {
            vector<int>list;

            // n times.
            for(int j = 0; j < n; j++)
            {
                //check if the jth bit of the number i is set or not.
                if(i & (1 << j))
                {
                    list.push_back(nums[j]);
                }
            }

            ans.push_back(list);
        }

        return ans;

        //TC : O(2^n *n)
        //SC : O(2^n *n)
    }
};