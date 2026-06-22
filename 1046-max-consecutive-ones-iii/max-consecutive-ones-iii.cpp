class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroes_count = 0;//If No. of zeroes are in the range of [0,k] than we can convert them IMAGINARILY INTO ONES.
        int max_len = INT_MIN;

        while(j < n)
        {
            if(nums[j] == 0)
            {
                zeroes_count++;
            }

            //If No. of zeroes in our window are > k i.e All zeroes in our window cant be converted into ones.i.e the zeroes_count th zero cannot be converted into ones.We will remove leftmost zero from our window and ,we will use operation of flipping it in flipping the rightmost zeroes_count th zero.see if max_len can be improved or not.


            //Invalid window shrink.
            while(zeroes_count > k)
            {
                if(nums[i] == 0)
                {
                    zeroes_count--;
                }
                i++;
            }

            max_len = max(max_len,j-i+1);
            j++;
        }

        return max_len;


    }
};