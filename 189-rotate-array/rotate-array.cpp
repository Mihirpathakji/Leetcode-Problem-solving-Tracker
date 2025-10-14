class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n=nums.size(); 
        vector<int>rotated_nums(n);

        // After rotating by the k places to the right the index of the rotated_nums should be [(i+k)%nums.length()]

        for(int i=0;i<n;i++)
        {
            rotated_nums[(i+k)%n]=nums[i];
        }   


    // Assigning the original_nums an value == to Rotated_nums so that the original nums got changed to the rotated_nums 

     nums=rotated_nums; 

    }
};