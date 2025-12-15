class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        int even_count=0;
        int odd_count=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[index]=nums[i];//ans[0]=nums[2]=2;ans[1]=nums[3]=4
                index++;//1  2 
            }
            //i==2;3
        }
        for(int i=0;i<n;i++)
        {//i==0
            if(nums[i]%2!=0)
            {
                ans[index]=nums[i];//ans[2]=nums[0]=3
                //ans=[2 4 3 1]
                index++;//3  4
            }
            //i==1  ;2  ;3;4
        }
        return ans;

        //TC:O(n)
        //SC:O(n)

    }
};