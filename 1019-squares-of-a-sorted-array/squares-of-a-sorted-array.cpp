class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        for(int i = 0;i< nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                nums[i] *= -1;
            }
        }
        //[4,1,0,3,10]
        sort(nums.begin(),nums.end());//[0,1,3,4,10]

        for(int i = 0; i <nums.size(); i++)
        {
            nums[i] = (nums[i]*nums[i]);
        }
        return nums;
        //TC : O(nlogn)
        //SC : O(1)
        
    }
};