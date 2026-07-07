class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int min_rows = m;
        int min_cols = n;

        int n1 = ops.size();

        for(int i = 0;i < n1;i++) {
    
            int a = ops[i][0];
            int b = ops[i][1];

            min_rows = min(min_rows,a);
            min_cols = min(min_cols,b);
        
        }

        int max_elements = min_rows*min_cols;

        return max_elements;

        //TC : O(10^4)
        //SC : O(1)

        
    }
};