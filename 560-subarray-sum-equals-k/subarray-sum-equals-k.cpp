class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
    int n=nums.size();
    
    int count=0;


    //n=3
    //i=0->2
    //j=0 ->2
    //j=0

    for(int i=0;i<n;i++){
        int prefix_sum=0;//
        for(int j=i;j<n;j++)
        {
            prefix_sum+=nums[j];//1
            if(prefix_sum==k)
            {
                count++;//
            }        
        }
    }
    return count;


    //TC:O(n^2)

    }
};