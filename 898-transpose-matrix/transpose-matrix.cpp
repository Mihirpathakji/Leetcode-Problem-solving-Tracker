class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();//3
        int n=matrix[0].size();//3
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++ )
        {
            for(int j=0;j<m;j++) 
            {
                ans[i][j]=matrix[j][i];
            }       
        }
        return ans;
        //m=2  n=3
        /*m=2  j=0->3
                ans(3,2)
                ans[0][0]=matrix[0][0]=1
                ans[0][1]=matrix[1][0]=4
                ans[0][2]=matrix[2][0]=7//the Resulting transposed matrix should have :n rows and m coulumns assigned in it.

        */

        //TC:O(n*m)
        //SC:O(n*m)
    }
};