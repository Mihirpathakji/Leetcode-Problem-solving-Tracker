class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        //[X,L,R] -> Difference array technique.

        int n = trips.size();
        vector<int>diff(1000+1,0);

        for(int i = 0;i < n; i++)
        {
            int X = trips[i][0];
            int L = trips[i][1];
            int R = trips[i][2];
  
            diff[L] += X;
            diff[R] -= X;
        }

        //Taking the prefix_sum.

        for(int i = 1; i <= 1000; i++)
        {
            diff[i] = diff[i-1] + diff[i];
        }                

        for(int i = 0;i <= 1000;i++)
        {
            if(diff[i] > capacity)
            {
                return false;
            }
        }

        return true;

    }
};