class Solution {
public:
    
    int minLights(vector<int>& lights) {

        int n = lights.size();

        vector<int>diff(n,0);//Stores whether the ith location is lighten or not.
        //diff[i] +ve means that ith location is lighten.
        //diff[i] -ve means that ith location is not lighten.

        int l = 0;
        int r = 0;

        for(int i =0; i<n;i++)
        {
            if(lights[i]!=0)
            {
                l = max(0, i - lights[i]);//left most boundary till which light can reach. 
                r = min(n - 1, i + lights[i]);//right most boundary till which light can reach.
                diff[l]++;

                if(r+1 < n)
                diff[r+1]--;
            }
        }


        //Now compute the Minimum number of bulbs needed to lighten every single location.

        int min_bulbs = 0;

        //After Computing the difference array -> We take it's prefix sum.

        int running_bulbs = 0;//stores prefixsum    

        for(int i = 0 ; i< n;i++)
        {
            running_bulbs += diff[i];
            if(running_bulbs == 0)
            {
                //not lighten.we need to place one bulb.
                min_bulbs++;
                running_bulbs++;
                //This bulb can enlighten from -1 to +1 pos.

                int pos = min(n-1,i+1);// greedily we will place the bulb at the i+1 th location.so both i and i+2 are covered in one go.

                int l = max(pos-1,0);
                int r = min(n-1,pos+1); 

                diff[l]++;

                if(r+1 < n)
                diff[r+1]--;
            }
        }

        return min_bulbs;

    }
};