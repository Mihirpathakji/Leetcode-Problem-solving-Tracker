class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int n = nums.size();
        int i = 0;
        int j = 1;
        int k = 2;
        int P_max = INT_MIN;

        while(j < n) {
            
           if(k == n) {
                i++;
                j++;
                k = j+1;
           }

            if(k >= n) {
                break;
            }

           if(nums[i] + nums[j] > nums[k]) {
                P_max = max(P_max,nums[i]+nums[j]+nums[k]);//8 9
                k++;
           }
           else {
                i++;
                j++;
                k = j+1;
           }
        }
        
        if(P_max == INT_MIN) {
            return 0;
        }

        return P_max;


    }
};