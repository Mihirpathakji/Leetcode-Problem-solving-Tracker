class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();


        int count = 0;

        for(int i = 0 ; i < 2*n-1 ; i++)
        {
            if(nums[i%n] <= nums[(i+1)%n])
            {
                count++;//
            }   
            else
            {
                count =1;
                continue;
            }
            if(count == n)
            {
                return true;
            }
        }
        return false;

    }
};