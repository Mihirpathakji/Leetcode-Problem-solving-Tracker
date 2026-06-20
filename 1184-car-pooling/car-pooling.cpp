class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();
        vector<pair<int,int>>weights;

        for(int i = 0; i < n; i++)
        {
            weights.push_back({trips[i][1],trips[i][0]});
            weights.push_back({trips[i][2],-trips[i][0]});
        }

        sort(weights.begin(),weights.end());

        int passenger_count = 0;

        for(int i = 0;i < weights.size(); i++)
        {
            passenger_count += weights[i].second;//2+=3 == 5

            if(passenger_count > capacity)
            {
                return false;
            }
        }
        
        return true;
        
    }
};