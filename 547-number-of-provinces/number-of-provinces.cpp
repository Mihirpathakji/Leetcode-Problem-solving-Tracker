class Solution {
public:

    void mydfs(int u,vector<bool>& visited,vector<vector<int>>& adjacency_list) {

        visited[u] = true;

        for(int i = 0;i < adjacency_list[u].size();i++) {
            
            if(adjacency_list[u][i] == 1) {
                if(!visited[i]) {
                    mydfs(i,visited,adjacency_list);
                }
            }

        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int v = isConnected.size();
   
        vector<bool>visited(v,false);
        int provinces = 0;

        for(int i = 0;i < v;i++) {
            
            if(visited[i] == false) {
                provinces++;
                mydfs(i,visited,isConnected);
            }
        
        }

        return provinces;

        //TC: O(v + 2*e)
        //SC : O(v)

    }
};