class Solution {
public:
    bool check(vector<int>& nums) {

        int n=nums.size();
        vector<int>original_nums(n);//O(n)
        for(int i=0;i<n;i++)
        {
            original_nums[i]=nums[i];
        }// O(n)

        sort(original_nums.begin(),original_nums.end());// O(nlogn) original nums contains sorted elements 

        // Now your nums is rotated by some number of positions .OKay i will again rotate it 
        // by number of rotations time i.e <= nums.length()  times .And at any instant of 
        // rotation if i  am getting the original nums back it means yes it was originally sorted 
        //  Then lets rotate it by <= nums.length() times and lets check if it is getting equated 
        // with the original one :

        // -> For Rotating upto <= nums.length() times :Where let r be the number of rotations.
        //Might occur that array nums given was sorted already .

        
        // This loops is to keep a count of the number of rotations we are rotating the given rotated nums
        vector<int>rotated_nums(n);

        for(int i=0;i<n;i++)
        {
            rotated_nums[i]=nums[i];
        }
        // rotated nums contains given elements 
        //  O(n)


        for(int r=0;r<=n;r++)
        {   

            // This rotates the nums by one time : 
            
            for(int i=0;i<n;i++)
            {
                rotated_nums[(i+r)%n]=nums[i];
            } 
            if(rotated_nums==original_nums)
                {
                    return true;
                }
        }
            return false;
            // TC : O(n^2)
            // Sc : O(n)


    }
};