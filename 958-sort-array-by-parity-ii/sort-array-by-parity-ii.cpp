class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int i=0;//even index 
        int j=1;//odd index 
        while(i<n && j<n)
        {
            if(nums[i]%2==0)
            {
                //even index contains an even element which is Good for sure.Lets check for the next i value.
                i+=2;
            }
            else if(nums[j]%2==1)
            {
                //odd index contains an odd element which is Good for sure,lets check for the next j value.
                j+=2;
            }
            else
            {
                //nums[i] which should be even is an Odd number and the nums[j] which should be odd is an even number .Both of them had the opposite Parity of what is wanted actually in both 
                swap(nums[i],nums[j]);
                i+=2;
                j+=2;
            }
        }
        return nums;

        //TC:O(n)
        //SC:O(1)

    }
};