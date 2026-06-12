class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();
        int counts = 0;
        
        sort(nums.begin(),nums.end());//nlogn

        //a -> index of shortest side.
        //b -> index of middle side.
        //c -> index of Largest side.

        //For every fixed value of c(Largest side).Find all valid pairs of {a,b,c->fixed}.With help of two pointers.as a and b 

        for(int c = n-1; c >= 2; c--)
        {
            int a = 0;//index of the shortest side.not value
            int b = c - 1; //index of middle side.not value.  

            //Fixed the largest side and the middle side.And count all possible valid shortest sides.

            while(a < b)
            {
                if( (nums[a] + nums[b]) > nums[c])
                {
                    counts += (b-a);//valid triplets.
                    
                    //there can be (b-a) valid positions for the shortest side a.with that b side as the middle side.Now With line count += (b-a) we had already counted all the triangles that can be formed using b as it's middle sid and all possible shorter side for that middle side .Now Count all other possible triangles with smaller b's as their middle side.
                    b--;
                }
                else
                {
                    a++;//12  
                }
            }
        }

        return counts;

        //TC : O(nlogn) + O(n^2)
        //SC : O(1)

    }
};