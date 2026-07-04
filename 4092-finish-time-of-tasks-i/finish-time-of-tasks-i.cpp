class Solution {
public:
    // Void DFS function using a visited tracking vector
    void dfs(int node, vector<vector<int>>& adj, vector<int>& baseTime, vector<long long>& finish_time, vector<bool>& visited) {

        // Mark the current node as visited right away
        visited[node] = true;

        // 1. Visit all unvisited children first
        
        for (int child : adj[node]) {
            if (!visited[child]) {
                dfs(child, adj, baseTime, finish_time, visited);
            }
        }

        // Base Case: If the node is a leaf node (has no children)
        if (adj[node].empty()) {
            finish_time[node] = baseTime[node];
            return;
        }

        // 2. Compute parent values using the already calculated children times
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        for (int child : adj[node]) {
            maxi = max(maxi, finish_time[child]);
            mini = min(mini, finish_time[child]);
        }

        // 3. Save the result for the current parent node
        finish_time[node] = 2 * maxi - mini + baseTime[node];
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]); // parent -> child
        }

        vector<long long> finish_time(n, -1);
        
        // Initialize the visited vector with size 'n' set to false
        vector<bool> visited(n, false);

        // Run the DFS from the root (node 0)
        dfs(0, adj, baseTime, finish_time, visited);

        return finish_time[0];
    }
};