class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        //Executing the PLAN to first start with LAND

        for(int i = 0; i < landStartTime.size(); i++)
        {
            long long min_time = 0;
            long long landtime = landStartTime[i];//99
            long long Landduration = landDuration[i];//59

            min_time += (landtime + Landduration);//158
            long long original = min_time;//158

            for(int j = 0 ;j < waterStartTime.size(); j++)
            {
                if(min_time >= waterStartTime[j]){

                    min_time += (waterDuration[j]);//178
                }
                else
                {
                    long long extra_time = waterStartTime[j] - min_time;
                    min_time += (extra_time + waterDuration[j]);
                }
                 ans = min(ans,min_time);//246 178
                 min_time = original;//158 158
            } 
        } 

        //Executing the PLAN to first start with water.

        for(int i = 0; i < waterStartTime.size(); i++)
        {
            long long min_time = 0;
            long long watertime = waterStartTime[i];//99 54
            long long waterduration = waterDuration[i];//85 20

            min_time += (watertime + waterduration);//184 74
            long long original = min_time;//184 74

            for(int j = 0 ;j < landStartTime.size(); j++)
            {
                if(min_time >= landStartTime[j]){

                    min_time += (landDuration[j]);//243
                }
                else
                {
                    long long extra_time = landStartTime[j] - min_time;//99-74 = 25
                    min_time += (extra_time + landDuration[j]);//74+= (25+59) = 158
                }
                ans = min(ans,min_time);//178 158 
                min_time = original;//184 74
            } 
        } 

        return ans;

        //TC : O(n^2)
        //SC : O(1)

        
    }
};