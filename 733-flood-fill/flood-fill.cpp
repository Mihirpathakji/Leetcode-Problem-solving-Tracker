class Solution {
public:

    void bfs(int& i,int& j,vector<vector<int>>& image,vector<vector<int>>& visited,int& color,queue<pair<int,int>>& q,int& original_color) {

        visited[i][j] = 1;
        q.push({i,j});
        int m = image.size();
        int n = image[0].size();

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            //Check for all it's neighbours in the 2D Matrix.

            for(int l =-1;l <= 1;l++) {
                for(int r = -1;r <= 1;r++) {
                    if(abs(l*r)!=1) {
                        if(row+l >=0 && row+l < m && col+r>=0 && col+r <n && visited[row+l][col+r] == false && image[row+l][col+r] == original_color) {
                            q.push({row+l,col+r});
                            visited[row+l][col+r] = 1;
                        }
                    }
                }
            }

        }

    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        //with [sr][sc] as a start performing bfs.

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>visited(m,vector<int>(n,false));
        queue<pair<int,int>>q;
        int original_color = image[sr][sc];

        bfs(sr,sc,image,visited,color,q,original_color);   

        for(int i = 0; i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(visited[i][j] == 1) {
                    visited[i][j] = color; 
                }
                else {
                    visited[i][j] = image[i][j];
                }
            }
        }     

        return visited;

        //TC : O(m*n*4) + O(m*n)
        //SC : O(m*n)

    }
};