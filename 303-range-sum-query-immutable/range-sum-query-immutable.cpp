class NumArray {
public:

    vector<int>ans;

    NumArray(vector<int>& nums) {
        ans = nums;
    }
    
    int sumRange(int left, int right) {
        
        long long ans1 = 0;

        for(int i = left; i <= right ; i ++)
        {
            ans1 += ans[i];
        }

        return ans1;
        
    }
};