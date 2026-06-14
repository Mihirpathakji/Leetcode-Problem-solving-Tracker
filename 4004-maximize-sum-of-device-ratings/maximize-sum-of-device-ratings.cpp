class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        
        //Dumping device is the one with smallest m2.Lets find it's index.
        int m = units.size();
        int n = units[0].size();

        long long min2_of_all = LLONG_MAX;
        long long min2_Sum = 0;
        long long min1_of_all = LLONG_MAX;
        long long min1_Sum = 0;

        for(int i = 0; i < m; i++)
        {
            long long first_min = LLONG_MAX;
            long long second_min = LLONG_MAX;

            for(int j = 0; j < n; j++)
            {
                if(units[i][j] < first_min)
                {   //4<3
                    second_min = first_min;//5
                    first_min = units[i][j];//3
                }
                else if(units[i][j] < second_min)
                {   
                    second_min = units[i][j];
                }
            }

            if(n==1)
            {
                second_min = 0;               
            }

            min1_Sum += first_min;
            min2_Sum += second_min;
            min2_of_all = min(min2_of_all,second_min);
            min1_of_all = min(min1_of_all,first_min); 
        }

        if(n == 1)
        {
            return min1_Sum;
        }
        return (min2_Sum - min2_of_all + min1_of_all);

        //TC : O(m*n)
        //SC : O(1)

    }
};