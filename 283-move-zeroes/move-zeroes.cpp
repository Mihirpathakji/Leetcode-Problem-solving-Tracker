class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
        //count no. of zeroes in the nums:
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }//count=2
        int index=0;
        for(int i=0;i<n;i++)
        {//i==1;i==2;i==3;4;5<5 
            if(nums[i]!=0)
            {
                nums[index]=nums[i];//nums[0]=nums[1]==1 nums[1]=nums[3]=3;nums[2]=nums[4]==12
                //[1 3 12]
                index++;//1 2 3
            }
        }

        while(count!=0)
        {
            nums[index]=0;//   //nums[3]=0 ;nums[4]=0
           index++; //4 5
            count--;//1  0
        }

        //TC:O(n)
        //SC:O(1)
    }
};