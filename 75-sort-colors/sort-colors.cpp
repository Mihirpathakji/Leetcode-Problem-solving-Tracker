class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        //blue red yellow.

        //Custom sorting using THREE POINTERS.

        int i = 0;//blue.
        int j = 0;//red.
        int k = n-1;//yellow . Since yellow is at the last in final answer.


        //Dutch National Flag Algorithm.In this nums[j] to nums[k] section is unvisited.// So visit every unvisited element in that section.


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