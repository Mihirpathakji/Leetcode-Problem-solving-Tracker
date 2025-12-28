class Solution {
public:

    bool valid_threshold(long long int your_divisor,vector<int>&nums,int threshold)
    {   
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil(double(nums[i])/your_divisor);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        long long int low = 1;//Minimal Divisor
        long long int high = *max_element(nums.begin(),nums.end());//Maximal Divisor
        long long int mid = -1;
        long long int ans=-1;
        
        while (low<=high) 
        {
            mid = low + (high - low)/2;//mid divisor
            //check if this divisor meets the threshold or not
            if(valid_threshold(mid,nums,threshold))
            {
                ans=mid;
                //find the minimum divisor
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;


        //TC:O(n*log(*max_arr))
        //SC:O(1)
    }
};