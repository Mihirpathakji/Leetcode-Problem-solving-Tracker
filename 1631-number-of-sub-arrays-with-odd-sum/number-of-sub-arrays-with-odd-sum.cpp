class Solution {
public:

    const long long MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();

        int prefix_sum = 0;
        int oddsum_count = 0;
        int evensum_count = 0;
        int ans = 0;

        for(int i = 0;i < n;i++) {
            
            prefix_sum += arr[i];

            if(prefix_sum % 2 == 1) {
                ans = (ans + evensum_count);
                oddsum_count++;
                ans++;
            }

            if(prefix_sum % 2 == 0) {
                //evensumed,if there inside exists a odd sum.Than odd+even = even.
                ans = (ans + oddsum_count) % MOD;
                evensum_count++;
            }

        }
        
        ans %= MOD;

        return ans;

        //TC : O(n)
        //SC : O(1)

    }
};