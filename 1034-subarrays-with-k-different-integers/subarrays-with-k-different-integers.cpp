class Solution {
public:

    int no_subarrays(int num,vector<int>&nums) {
    
        int k = num;//1.
        int n = nums.size();

        //No. of subarrays with atmost k distinct elements.

        int i = 0;
        int j = 0;
        int counts = 0;

        unordered_map<int,int>mp;

        while(j < n) {
            
            //O(N)

            mp[nums[j]]++;// 1.2.2.

            //O(N) Over the entire looping.

            while(mp.size()  > k) {

                mp[nums[i]]--;//1.

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i++;//1.2.3.//1.2.3.4.

            }

            counts += (j-i+1);//[1].3.6.10.12.3.

            //1.2.3.4.5.

            j++;//1.2.3.4.5.//1.2.//2.3.4.5.

        }

        return counts;//12.

        //O(N+N) = O(2*N).

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n = nums.size();

        return no_subarrays(k,nums) - no_subarrays(k-1,nums);//12..5

        //TC : O(2*N)

        //SC : O(2*N)
        
    }
};