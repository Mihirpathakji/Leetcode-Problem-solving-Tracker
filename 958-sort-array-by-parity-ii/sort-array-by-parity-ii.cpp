class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        vector<int>ans(n);
        int evenindex=0;
        int oddindex=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[evenindex]=nums[i];//ans[0]=nums[0]==4  ans[2]=nums[1]==2
                evenindex+=2;//2
                //ans[]=[4 5  2 7]
                //ans[0]=2
            }   
            else
            {
                ans[oddindex]=nums[i];//ans[1]=nums[2]==5;ans[3]=nums[3]==7
                oddindex+=2;//3;
                //ans[1]=nums[1]==3
            }
            //i==1;2;3
            //i==1;2
        }
        return ans;

    //[2,3]->   n=2
    //ans[]=[2 3]
        //TC:O(n)
        //SC:O(n)

    }
};