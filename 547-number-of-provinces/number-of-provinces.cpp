class Solution {
public:

    void mybfs(queue<int>& q,int start,vector<bool>& visited,vector<vector<int>>& isConnected) {

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {

            int temp = q.front();//0 1 2 3 4
            q.pop();

            for(int i = 0;i < isConnected[temp].size();i++) {

                //check if it is neighbour or not.
                if(isConnected[temp][i] == 1) { 
                    if(visited[i] == false) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }

        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();//5
        int bfs_count = 0;
        vector<bool>visited(V,false);
        queue<int>q;

        for(int i = 0;i < V;i++) {
            
            if(visited[i] == false) {
                bfs_count++;//2
                mybfs(q,i,visited,isConnected);
            }

        }

        return bfs_count;//2   

        //TC : O(V + 2*E)
        //SC : O(V)

    }
};