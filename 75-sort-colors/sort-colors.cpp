class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count0=0;
        int count1=0;
        int count2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count0++;
            }
            else if(nums[i]==1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int index=0;
        while(index<count0)
        {
            nums[index]=0;//nums[0]=0  nums[1]=0
            index++;//1    2   
        }
        while(count1!=0)
        {
            nums[index]=1;  //nums[2]=1  nums[3]=1
            index++;//3   4
            count1--;//1 0
        }
        while(count2!=0)
        {
            nums[index]=2;// nuns[4]=2  nums[5]=2
            index++;//5  6
            count2--;//1  0 
        }
        //TC:O(n)
        //SC:O(1)
    }   

};