class Solution {
public:
    int trap(vector<int>& heights) {

        //Most Optimal Solution :-  SC:O(1) and TC:O(n) using TWO-POINTERS.

        int n=heights.size();
        int l=0;
        int r=n-1;
        int ans=0;
        int left_max=0;
        int right_max=0;
        while(l<r)
        {   
            //calculate the left_max and the right_max everytime;
            left_max=max(left_max,heights[l]);
            right_max=max(right_max,heights[r]);

            //Minimum out of the left_max and the right_max is the Deciding factor for the Amount of the Water that is Trapped.

            //case1:
            if(left_max<right_max)
            {
                ans+=(left_max-heights[l]);
                //done with that i pointer now left_max is needed in reference to the next i 
                l++;
            }

            //case2:
            else
            {
                ans+=(right_max-heights[r]);
                r--;
            }
        }
        return ans;
    //TC:O(n)
    //SC:O()

    }
};