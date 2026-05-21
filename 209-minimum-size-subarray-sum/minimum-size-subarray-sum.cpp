class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        vector<int>prefix_arr(n);
        prefix_arr[0] = nums[0];

        for(int i = 1 ; i < n; i++)
        {
            prefix_arr[i] = nums[i] + prefix_arr[i-1];
        }

        int i = 0;
        int j = 0;
        long long int curr_sum = 0;
        int ans = INT_MAX;
        bool flag = false;
      
        while(j < n)
        {
            if(i == 0)
            {
                curr_sum = prefix_arr[j];
            }
            else
            {
                curr_sum = prefix_arr[j] - prefix_arr[i-1];
            }

            if(curr_sum >= target)
            {
                ans = min(ans,j-i+1);//2
                flag = true;
                j = i;
                i++;
            }
            j++;
        }

        if(!flag)
        {
            return 0;
        }
        return ans;

        //TC :O (n)
        //SC : 
    }
};