class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

       long long maxi = *max_element(nums.begin(),nums.end());
       long long mini = *min_element(nums.begin(),nums.end());

       long long value = maxi - mini;

       //Take the whole array for k times yields maximum total value.Since we get maximum value in each kth operation.

       long long ans = value*k;
       return ans;        

        //TC : O(n)
        //SC : O(1)
    }
};