class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
        int j=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;//3 
            }
            else
            {
                count++;
            }
        }

        for(int i=j;i<n;i++)
        {
            nums[i]=0;
        }


        //Tc : O(n)
        //Sc : O(1)


    }
};