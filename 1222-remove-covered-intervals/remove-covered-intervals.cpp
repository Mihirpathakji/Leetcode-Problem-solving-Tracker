class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

       int n = intervals.size();

        auto mylambda = [](vector<int>a,vector<int>b) {
            
           if(a[0] == b[0]) {
                return a[1] > b[1];
           }

           return a[0] < b[0];

        };

        sort(intervals.begin(),intervals.end(),mylambda); 

        vector<vector<int>>result;
        result.push_back(intervals[0]);

        for(int i = 1;i < n;i++) 
        {   
            int c = result.back()[0];
            int d = result.back()[1];

            int a = intervals[i][0];
            int b = intervals[i][1];

            if(c <= a && b <= d) {
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();

        //TC : O(nlogn)
        //SC : O(n)


    }
};