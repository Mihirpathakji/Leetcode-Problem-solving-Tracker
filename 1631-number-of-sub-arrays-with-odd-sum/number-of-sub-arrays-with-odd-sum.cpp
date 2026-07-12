class Solution {
public:

    const long long MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();

        int prefix_sum = 0;
        int odd_subarr = 0;
        int even_subarr = 1;
        int ans = 0;

        for(int i = 0;i < n;i++) {
            
            prefix_sum += arr[i];

            if(prefix_sum % 2 == 0) {
                //evensumed,if there inside exists a odd sum.Than odd+even = even.
                ans = (ans + odd_subarr) % MOD;
                even_subarr++;
            }
            else {
                //oddsummed,if there exists a evensummed inside it.Than that even + odd = odd.
                ans = (ans + even_subarr) % MOD;
                odd_subarr++;
            }
        }
        
        ans %= MOD;

        return ans;


        //TC : O(n)
        //SC : O(1)

    }
};