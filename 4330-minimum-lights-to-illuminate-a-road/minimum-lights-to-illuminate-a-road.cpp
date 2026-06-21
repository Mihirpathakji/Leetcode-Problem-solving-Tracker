class Solution {
public:
    
    int minLights(vector<int>& lights) {

        int n = lights.size();

        vector<int>diff(n,0);//Change in the number of active bulbs at location i.

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

        int running_bulbs = 0;//stores prefixsum  : Total Number of bulbs illuminating the ith location. 

        for(int i = 0 ; i< n;i++)
        {
            running_bulbs += diff[i];//0  
            if(running_bulbs == 0)
            {
                //No active bulb to illumiate ith location.
                min_bulbs++;//1
                running_bulbs++;//Now there is one bulb to illuminate that ith location.
                //This bulb can enlighten from -1 to +1 pos.//

                int pos = min(n-1,i+1);// greedily we will place the bulb at the i+1 th location.so both i and i+2 are covered in one go.//place bulb at (i+1)th.

                //Now this placed bulb can may enlighten the other bulbs on it's left and right.So we need to specify those ranges of enlightening in the diff[i]

                int l = max(pos-1,0);//ith location set 1
                int r = min(n-1,pos+1);//i+2 th location 

                if(r+1 < n)
                diff[r+1]--;//it is (i+3)th one set --.
            }
        }

        return min_bulbs;

    }
};