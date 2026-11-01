class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int i = 0;//0
        int j = 0;//1
        int k = n-1;//2.Bcz 2 is at the last position.

        while(j <= k) {

            if(nums[j] == 2) {
                swap(nums[j],nums[k]);
                k--; 
            }
            
            else if(nums[j] == 0) {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        //TC : O(n)
        //SC : O(1)

    }
};