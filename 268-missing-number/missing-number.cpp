class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();// 10
         int hasharr[10001]={0};
        
        // Precompute : 
        
        for(int i=0;i<n;i++)
        {
            hasharr[nums[i]]+=1;//hasharr[nums[o]]+=1  -> hasharr[9]=1 i.e element 9 is present 
            //hash[9];hash[6];hash[4];hash[2];hash[3];hash[5];hash[7];hash[0];hash[1]
            //hash[0],hash[1],hash[2],hash[3],hash[4],hash[5],hash[6],hash[7],hash[9];but hash[8] is still ZERO SINCE ALL ARE INITIALIZED BY ZERO .
        }

        int x=0;
        for(int j=0;j<n;j++)
        {
            if(hasharr[j]==0)
            {
                x=j;// x=8 
                return x;// 8 
            }
            //j=2 <10  j=3 <10  j=4 <10 j=5  j=6  j=7 j=8 b
        }
        return nums.size();
    
        return 0;


        //TC : O(n)
        //Sc : O(n)

    }
};