class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        //Algo : If a boundary O can touch that O i.e that O cant be converted into a X since that O is not surrounded since it is in a group where atleast one O is at the boundary.

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;//{i,j}

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if( ( i == 0 || i == m-1 || j == 0 || j == n-1 ) && board[i][j] == 'O' ) {
                    q.push({i,j});
                    visited[i][j] = true;    
                }
            }
        }

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int row_dir[4] = {0,-1,0,1};// 
            int col_dir[4] = {-1,0,1,0};//

            for(int i = 0; i < 4;i++) {
                if(row + row_dir[i] >=0 && row + row_dir[i] < m && col + col_dir[i] >= 0 && col + col_dir[i] < n && visited[row + row_dir[i]][col + col_dir[i]] == false && board[row + row_dir[i]][col + col_dir[i]] == 'O') {

                    q.push({row + row_dir[i] , col + col_dir[i]});
                    visited[row + row_dir[i]][col + col_dir[i]] = true;
                }
            }
        }

        //If still any O's are not visited i.e they do not have any 'O' neighbour on the boundary.i.e are completely surrounded by 'X' Since those set of O's have no O's neighbour on boundary. 

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(board[i][j] == 'O' && visited[i][j] == false) {
                    //it is in surrounded region.

                    board[i][j] = 'X';
                }
            }
        }
        
        return;   

        //TC : O(m*n*4)
        //SC : O(m*n)
        
    }
};