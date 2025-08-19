class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());// O(n)
        for(auto it:nums){
            cout << it;
        }

        //Tc : O(n)

    }
};