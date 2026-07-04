class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

     //Merge Overlapping intervals and final ans is Number of intervals.       

        int cnt = points.size();
        sort(points.begin(),points.end());

        int min_right = points[0][1];
        int n = cnt;

        for(int i = 1;i < n;i++) {
            
            if(points[i][0] <= min_right) {
                cnt--;
                min_right = min(min_right,points[i][1]);
            }
            else {
                min_right = points[i][1];
            }

        }

        return cnt;

        
    }
};