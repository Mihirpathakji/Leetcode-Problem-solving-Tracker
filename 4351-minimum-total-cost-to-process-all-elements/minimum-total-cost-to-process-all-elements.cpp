class Solution {
public:

    const long long MOD = 1e9 + 7;
    
    int minimumCost(vector<int>& nums, int k) {

        int n = nums.size();

        long long mx_ops = 0;
        long long used = 0;

        for(int i = 0;i < n;i++) {
            used += nums[i];

            if(used > k) {
                mx_ops = max(mx_ops,((used-1)/k));
            }

        }

        long long a = mx_ops;
        long long b = mx_ops + 1;
        if(a%2 == 0) {
            a/=2;//1
        }
        else {
            b/=2;
        }

        a%=MOD;
        b%=MOD;

        long long ans = (a*b)%MOD;

        return (int)ans;

        //TC : O(n)
        //SC : O(1)

    }
};