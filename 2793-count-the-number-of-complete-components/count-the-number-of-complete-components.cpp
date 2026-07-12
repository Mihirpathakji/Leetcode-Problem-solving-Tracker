class Solution {
public:

    bool bfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>&adj_list) {

        int node_count = 0;
        queue<int>q;
        q.push(u);
        visited[u] = true;
        node_count++;//1 -> 5
        int total_edges_in_component = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            total_edges_in_component += adj_list[node].size(); 
            for(auto v : adj_list[node]) {   
                if(!visited[v])
                {
                    node_count++;//2 3
                    q.push(v);//3 4 
                    visited[v] = true;
                }
            }
        }

        return node_count*(node_count-1) == total_edges_in_component;

    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        //Clue : If the graph has a connected component with v vertices in that component than the total number of the edges that must be V*(V-1).Since, Every V node is connected with  (V-1) other vertices. Hence total edges must = V*(V-1).

        unordered_map<int,vector<int>>mp;
        
        for(auto vec : edges) {

            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v);
            mp[v].push_back(u);  
        }

        int counts = 0;
        vector<bool>visited(n,false);

        for(int i = 0;i < n;i++) {
            if(!visited[i]) {
                if(bfs(i,visited,mp)) {
                    counts++;
                }
            }
        }

        return counts;

        //TC : O(V + 2*E)
        //SC : O(V)
        
    }
};