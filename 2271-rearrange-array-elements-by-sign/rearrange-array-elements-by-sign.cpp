class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int evenindex=0;//would track all the evenindexes
        int oddindex=1;//would track all the oddindexes
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[evenindex]=nums[i];//ans[0]=nums[0]=3   ans[2]=nums[1]=1  //ans[4]=nums[4]==2
                evenindex+=2;//2 4 6
            }
            else
            {
                ans[oddindex]=nums[i];//ans[1]=nums[2]=-2   //ans[3]=nums[3]=-5//ans[5]=nums[5]=-4
                oddindex+=2;//3//5
            }
            //i==1;2;3;4;5
            //ans[]=[3 -2  1 -5 2 -4]
        }
            return ans;

            //TC:O(n)
            //SC:O(n)
    }
};