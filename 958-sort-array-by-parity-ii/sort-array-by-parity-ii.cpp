class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int i=0;//even index 
        int j=1;//odd index
        while(i<n && j<n)
        {   
            while(i<n && nums[i]%2==0)    
            {
                i+=2;
            }
            
            while(j<n && nums[j]%2==1)    
            {
                j+=2;
            }

            if(i<n && j<n)
            {
                swap(nums[i],nums[j]);
            }  
        }
        return nums;
    }
};