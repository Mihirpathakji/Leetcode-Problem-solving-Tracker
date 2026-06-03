class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        //Path1 : Land to water : 

        int final_ans = INT_MAX;
            
        int land_ride_complete_time = INT_MAX;//Minimum total time to complete the land ride.
        for(int i = 0 ; i  < landStartTime.size(); i ++)
        {
            land_ride_complete_time = min(land_ride_complete_time,landStartTime[i] + landDuration[i]);
        }//44

        //for this land_ride_complete_time -> see the minimum total time we could make in total while taking the all possible water routes.

        int can_be_ans = INT_MAX;
        for(int i = 0;i < waterStartTime.size(); i++)
        {
            can_be_ans = min(can_be_ans,max(land_ride_complete_time,waterStartTime[i]) + waterDuration[i]);//44+91 = 135  54+71 = 125  125
        }

        final_ans = min(final_ans,can_be_ans);//125

        //Path2 : water -> land

        int water_ride_complete_time = INT_MAX;
        for(int i = 0 ; i  < waterStartTime.size(); i ++)
        {
            water_ride_complete_time = min(water_ride_complete_time,waterStartTime[i] + waterDuration[i]);
        }//97

        //for this water time find the minimum time we could make in total while taking the all possible land routes.

        can_be_ans = INT_MAX;
        for(int i = 0; i < landStartTime.size(); i++)
        {
            can_be_ans = min(can_be_ans,max(water_ride_complete_time,landStartTime[i]) + landDuration[i]);//97+42 = 139 // 97+30 = 127 -> 127
        }

        final_ans = min(final_ans,can_be_ans);//min(125,127) = 125

        return final_ans;

        //TC : O(n+m)
        //SC : O(1)

    }
};