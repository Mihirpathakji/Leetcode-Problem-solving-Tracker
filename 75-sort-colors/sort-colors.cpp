class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        //blue red yellow.

        //Custom sorting using THREE POINTERS.

        int i = 0;//blue.
        int j = 0;//red.
        int k = n-1;//yellow.

        while(j <= k) {

            if(nums[j] == 2) {
                swap(nums[k],nums[j]);
                k--;
            }

            else if(nums[j] == 1) {
                j++;
            }

            else {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }

        return;





        
    }
};