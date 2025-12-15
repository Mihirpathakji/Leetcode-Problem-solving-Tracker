class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());//nlogn[1 2 3 4]
        int i=0;
        int j=n-1;//[4 2 3 1]
        while(i<j)
        {
            if(nums[i]%2==0)
            {
                i++; //2 4 
            }
            else
            {
                if(nums[j]%2==0)
                {
                    swap(nums[i],nums[j]);
                    i++;//3
                    j--;//4
                }
                else
                {
                    j--;//5
                }
            }
        }
        return nums;

        //TC:O(nlogn)
        //SC:O(1)
    }
};