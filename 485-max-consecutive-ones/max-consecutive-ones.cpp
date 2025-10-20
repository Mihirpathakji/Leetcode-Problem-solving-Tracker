class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int j=0;
        int ans=0;
        int n=nums.size();
        int ans2=0;
        for(int i=0;i<n;i++)
        {//i==2 <6  ;3;4;5
            if(nums[i]==1)
            {
                ans=max(ans,(i-j+1));//1 ;max(2,3)==3;
                if(i==n-1)
                {
                    ans2=max(ans2,ans);
                }
            }
            else
            {
                j=i+1;//3 
                ans2=max(ans,ans2);//2
                ans=0;
            }
        }
        return ans2;

        //TC : O(n)
        //SC : O(1)
    }
};