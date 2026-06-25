class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();

        //Sliding window : (Something atleast or atmost k)

        int i = 0;
        int j = 0;

        unordered_map<int,int>mp;//Stores the Past count of that number.
        int pairs_count = 0;
        long long counts = 0;

        while(j < n)
        {
            pairs_count += mp[nums[j]];
            mp[nums[j]]++;

            //If a window has good subarray.[i,j]Than upto how many valid i can i shrink the window such that the subarray remains good.


            while(pairs_count >= k)
            {
                //Check how many valid subarrays can be made with that fixed j and i moving to all i < j.

                counts += (n-j);
                //Shrink :

                mp[nums[i]]--;
                pairs_count -= mp[nums[i]];
                i++;

                //No. of pairs also gets reduced by the updated frequnecy.

            }

            j++;
        }

        return counts;

        //TC : O(n)
        //SC : O(n)
        
    }
};