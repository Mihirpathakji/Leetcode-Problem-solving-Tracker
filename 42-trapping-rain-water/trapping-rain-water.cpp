class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int l  = 0;
        int r = n - 1;

        int leftmax = 0;
        int rightmax = 0;

        int amount_of_water = 0;

        while(l < r)
        {
            leftmax = max(leftmax,height[l]);
            rightmax = max(rightmax,height[r]);

            //Amount of water trap depends on the minimum of the leftmax and rightmax

            if(leftmax < rightmax)
            {
                amount_of_water += leftmax - height[l];
                l++;
            }
            else
            {
                amount_of_water += rightmax - height[r];
                r--;
            }
        } 

        return amount_of_water;
        //TC:O(N)
        //SC:O(1)
    }
};