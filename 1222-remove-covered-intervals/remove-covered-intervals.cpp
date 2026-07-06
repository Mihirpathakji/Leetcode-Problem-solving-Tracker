class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        auto mylambda = [](vector<int>a,vector<int>b) {
            
            //Handle the Edge case first.

            if(a[0] == b[0]) {
                return a[1] > b[1];//If first element of both comes out to be same -> Sort in descending order of the second element.
            }

           return a[0] < b[0];//Else ascending order of the first element.

        };

        sort(intervals.begin(),intervals.end(),mylambda); 

        int c = intervals[0][0];//1
        int d = intervals[0][1];//7 

        int counter = 1;//1

        for(int i = 1;i < n;i++) 
        {   

            int a = intervals[i][0];//1 1 2
            int b = intervals[i][1];//4 2 8 

            if(c <= a && b <= d) {
                continue;//Remove this (a,b) pair so dosent contribute to the ans.
            }
            else {

                d = b;
                c = a;
                counter++;
            }
        }

        return counter;

        //TC : O(nlogn)
        //SC : O(1)


    }
};