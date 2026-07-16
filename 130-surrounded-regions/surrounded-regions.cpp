class Solution {
public:

    void dfs(int u,int v,vector<vector<bool>>&visited,vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size(); 
        visited[u][v] = true;//T  

        //We went to the Adjacency_List of u in standard dfs.But here there is no adjacency_list available in Matrix problems.The only adjacency_list is the all four directions , directly connected elements.

        int row_dir[4] = {0,-1,0,1};// 
        int col_dir[4] = {-1,0,1,0};

        for(int i = 0;i < 4;i++) {
            if(row_dir[i] + u >= 0 && row_dir[i] + u < m && v + col_dir[i] >= 0 && v + col_dir[i] < n && visited[u + row_dir[i]][v + col_dir[i]] == false && board[u + row_dir[i]][v + col_dir[i]] == 'O') {
                dfs(row_dir[i] + u , col_dir[i] + v , visited,board);
            }
        }

    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        //Algo : If a boundary O can touch that O i.e that O cant be converted into a X since that O is not surrounded since it is in a group where atleast one O is at the boundary.

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if( ( i == 0 || i == m-1 || j == 0 || j == n-1 ) && board[i][j] == 'O' && visited[i][j] == false ) {
                    dfs(i,j,visited,board);
                }
            }
        }    

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(board[i][j] == 'O' && visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }   
        }   

        return;

        //TC : O(m*n)
        //SC : O(m*n)
    }
};