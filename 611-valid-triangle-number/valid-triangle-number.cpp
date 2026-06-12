class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();
        int counts = 0;
        
        sort(nums.begin(),nums.end());//nlogn

        //For every fixed value of c.Find all valid pairs of {a,b,c->fixed}.With help of two pointers.as a and b 

        for(int c = n-1; c >= 2; c--)
        {
            int a = 0;
            int b = c - 1; 

            while(a < b)
            {
                if((nums[a] + nums[b]) > nums[c])
                {
                    counts += (b-a);//there can be (b-a) valid positions for the number a.with that b side as the middle side.Now With line count += (b-a) we had already counted all the triangles that can be formed using b as it's middle side.Now Count all other possible triangles with smaller b's as their middle side.
                    b--;
                }
                else
                {
                    a++;
                }
            }

        }

        return counts;

        //TC : O(nlogn) + O(n^2)
        //SC : O(1)


    }
};