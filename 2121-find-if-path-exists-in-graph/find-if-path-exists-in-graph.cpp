class Solution {
public:
    
    bool dfs(int node,int destination,unordered_map<int,vector<int>>& adj_list,vector<int>& visited) {

        visited[node] = 1;

        if(node == destination) {
            return true;
        }

        for(auto& v : adj_list[node]) {

            if(visited[v] == 0) {
                if(dfs(v,destination,adj_list,visited) == true) {
                    return true;
                }  
            }
        }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int,vector<int>>adj_list;

        for(int i = 0;i < edges.size();i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

        }

        //dfs from source.If the source can reach the destination than we are good to go.

        vector<int>visited(n,0);
        
        return dfs(source,destination,adj_list,visited);

    }
};