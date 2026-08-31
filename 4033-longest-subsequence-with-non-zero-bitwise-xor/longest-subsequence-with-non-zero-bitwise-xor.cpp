class Solution {
public:
   
    int longestSubsequence(vector<int>& nums) {

        int n =  nums.size();

        int i = 0;
        int XOR = 0;
        bool non_zero = false;

        while(i < n) {
            if(nums[i]!=0) {
                non_zero = true;//there is atleast one non zero element.
            }

            XOR^=  nums[i];
            i++;
        }

        if(XOR!=0) {
            return n;
        }

        else {
            if(non_zero) {
                //i can remove this element and can get final_XOR = non_zero_element.
                return n-1;//so the xor of the remaining n-1 element = that non zero element.
            }
            else {
                return 0;
            }
        }
        
    }
};