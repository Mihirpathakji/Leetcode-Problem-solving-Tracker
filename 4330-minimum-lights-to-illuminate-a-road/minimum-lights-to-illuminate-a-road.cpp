class Solution {
public:
    int minLights(vector<int>& lights) {

        int n = lights.size();

        vector<int>diff(n,0); 

        for(int i = 0; i  < n;i++)
        {
            if(lights[i]!=0)
            {
                //take the range upto which it illuminates light.
                int v = lights[i];
                int l = max(0, i - v) ;
                int r = min(n - 1, i + v);

                diff[l]++;

                if(r+1 < n)
                {
                    diff[r+1]--;
                }
            }
        }


        int min_bulbs = 0;
        
        int prefix_sum = 0;//Gives the cumulative number of bulbs that lighten the ith location.

        for(int i = 0 ; i < n;i++)
        {
            prefix_sum += diff[i];

            if(prefix_sum == 0)
            {   
                //i.e No bulb is there which illuminates this ith location.
                min_bulbs++;//we inserted a new bulb.
                prefix_sum++;//One more bulb added.

                //you need to Modify the righmost range upto which this newly inserted bulb will lighten.

                //If there is no bulb lightening ith location , we will insert the new bulb at the (i+1)th location greedily .
                
                int pos = min(n-1,i+1);

                int r = min(n-1,pos+1);//getting (i+2)th one pos ater bulb got inserted.light of new bulb can reach here.

                //set -1 at (i+3)th location where the light of the newly inserted bulb at the (i+1)th location cant reach.
                
                if(r+1 < n)
                diff[r+1]--;
            }
        }
        return min_bulbs;
        
    }
};