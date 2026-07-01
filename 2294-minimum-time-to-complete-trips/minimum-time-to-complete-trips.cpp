class Solution {
public:

    bool possible_to_done(long long min_time,vector<int>& time,int totalTrips) {

        long long trips_done = 0;    

        for(int i = 0;i < time.size();i++) {
            trips_done += (min_time/time[i]);
        }

        return trips_done>=totalTrips;

    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        int n = time.size();

        long long low = 1;
        long long high = *max_element(time.begin(),time.end())*(long long)totalTrips;
        long long ans = 1;

        while(low <= high) {

            long long mid = low + (high-low)/2;

            if(possible_to_done(mid,time,totalTrips)) {
                //store it and look for the minimum.
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;  
            }
        }

        return ans;

        //TC : O(n*log1e14) 
        //SC : O(1)

    }
};