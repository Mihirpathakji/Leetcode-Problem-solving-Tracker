class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int min_right_boundary = intervals[0][1];//2
        int min_removes = 0;

        for(int i = 1;i < n;i++) {

            if(intervals[i][0] < min_right_boundary) {
                min_removes++;
                //remove the one with larger rightboundary.
                //kept the one with smaller right boundary.So that there will be lesser needs to remove future intervals.

                min_right_boundary = min(min_right_boundary,intervals[i][1]);
            }
            else {
                min_right_boundary = intervals[i][1];
            }
        }

        return min_removes;


    }
};