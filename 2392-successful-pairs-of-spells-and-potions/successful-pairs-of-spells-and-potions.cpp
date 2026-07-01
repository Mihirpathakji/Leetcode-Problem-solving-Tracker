class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size();
        int m = potions.size();
        vector<int>pairs(n);

        sort(potions.begin(),potions.end());//1.sorted.2.Monotonicity.

        for(int i = 0; i < n; i++) {

            long long ans = -1;
            int low = 0;
            int high = m-1;

            while(low <= high) {
                int mid = low + (high-low)/2;

                if((long long)potions[mid]*spells[i] >= success) {
                    ans = mid;//store and look for the minimum mid.
                    high = mid-1;
                }
                else {
                    low = mid +1;
                }
            }
            if(ans == -1) {
                pairs[i] = 0;
            }
            else {
                pairs[i] = m-ans;
            }
        }

        return pairs;

        //TC : O(n*logm)
        //SC : O(1)
    }
};