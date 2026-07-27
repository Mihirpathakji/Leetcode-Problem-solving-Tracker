class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        //Find first two maximum in an array.

        int first_maximum = 0;
        int second_maximum = 0;

        for(int i = 0;i < n;i++) {

            if(nums[i] > first_maximum) {
                second_maximum = first_maximum;
                first_maximum = nums[i];
            }
            else if(nums[i] > second_maximum){
                
                second_maximum = nums[i];
            }   
        }

        return (first_maximum-1)*(second_maximum-1);


    }
};