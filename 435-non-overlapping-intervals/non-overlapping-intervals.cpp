class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        //1.To find intervals easily -> 1.Sort the array...1.Greddy.

        sort(intervals.begin(),intervals.end());//so we can imagine them on numberline.

        int n = intervals.size();

        int min_removes = 0;
        int min_right = intervals[0][1];

        for(int i = 1;i < n;i++) {
            
            if(intervals[i][0] < min_right) {
                min_removes++;//1 2
                min_right = min(min_right,intervals[i][1]);
            }
            else {
                min_right = intervals[i][1];
            }

        }
        
        return min_removes;

    }
};