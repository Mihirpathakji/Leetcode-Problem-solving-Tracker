class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;          // Tracks: element -> frequency
            unordered_map<int, int> freq_counts; // Tracks: frequency -> how many elements have it

            for (int j = i; j < n; j++) {
                int val = nums[j];
                int old_freq = mp[val];
                int new_freq = old_freq + 1;

                // 1. Update element frequency
                mp[val] = new_freq;

                // 2. Safely update the frequency-of-frequencies map in O(1)
                if (old_freq > 0) {
                    freq_counts[old_freq]--;
                    if (freq_counts[old_freq] == 0) {
                        freq_counts.erase(old_freq); // Keep map size accurate
                    }
                }
                freq_counts[new_freq]++;

                // 3. Perform O(1) balance checks directly using map sizes
                if (mp.size() == 1) {
                    max_len = max(max_len, j - i + 1);
                } 
                else if (freq_counts.size() == 2) {
                    auto it = freq_counts.begin();
                    int f1 = it->first;
                    int f2 = next(it)->first; // Safely jump to the second frequency

                    if (f1 == 2 * f2 || f2 == 2 * f1) {
                        max_len = max(max_len, j - i + 1);
                    }
                }
            }
        }

        return max_len;
    }
};