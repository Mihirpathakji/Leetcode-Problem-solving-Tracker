class Solution {
public:

    bool bfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>&adj_list,vector<vector<bool>>& connection) {

        vector<int>storage;

        queue<int>q;
        q.push(u);
        visited[u] = true;
        storage.push_back(u);

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto v : adj_list[node]) {   
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                    storage.push_back(v);       
                }
            }
        }

        //{0,1,2}.

        for(int i = 0;i < storage.size();i++) {
            for(int j = 0;j < storage.size();j++) {
                if(i!=j && connection[storage[i]][storage[j]] == false) {
                    return false;
                }
            }
        }

        return true;

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<bool>>connection(n,vector<bool>(n,false));

        unordered_map<int,vector<int>>mp;
        for(auto vec : edges) {
            int u = vec[0];
            int v = vec[1];

            connection[u][v] = true;
            connection[v][u] = true;

            mp[u].push_back(v);
            mp[v].push_back(u);  
        }

        int counts = 0;
        vector<bool>visited(n,false);

        for(int i = 0;i < n;i++) {
            if(!visited[i]) {
                if(bfs(i,visited,mp,connection)) {
                    counts++;
                }
            }
        }

        return counts;


        
    }
};