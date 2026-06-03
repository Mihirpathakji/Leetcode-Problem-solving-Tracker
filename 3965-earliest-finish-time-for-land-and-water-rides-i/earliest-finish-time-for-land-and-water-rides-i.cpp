class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();//2
        int m =  waterStartTime.size();//1

        int earliest_time = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {

                //ith landfinish and used jth waterDuration.
                int landFinishTime = landStartTime[i] + landDuration[i];
                int land_water_time = max(landFinishTime,waterStartTime[j]) + waterDuration[j];

                earliest_time = min(earliest_time,land_water_time);


                //jth waterfinish and used ith landDuration. 
                int waterFinishTime = waterStartTime[j] + waterDuration[j];
                int water_land_time = max(waterFinishTime,landStartTime[i]) + landDuration[i];

                earliest_time = min(earliest_time,water_land_time);
            }
        }
        return earliest_time;
    }
};