class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //[ 1 1 2 ]
        //Most optimal approach :

        int n=nums.size(); //3
        int j=0;
        int size=0;
        int i=0;
        for(i=0;i<n-1;i++)
        {
            //0<2 2 times 
            //i==0<2
            if(nums[i]!=nums[i+1])
            {
                nums[j]=nums[i];//nums[0]=nums[1]==1 
                size++;//1
                j++;//1
            }
            //i==1   2 
        }

        //if size of the array is only one  :
        if(n==1)
        {
            return n;
        }

        // Manually Adding the last element  for the Last index
            nums[j]=nums[i];//nums[1]==nums[2]==2
            size++;//2


        return size;

        //Tc : O(n)
        //Sc : O(1)
    }
};