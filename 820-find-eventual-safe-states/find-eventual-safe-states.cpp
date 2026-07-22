class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<vector<int>>adj_rev(V);
        vector<int>indegree(V,0);

        for(int i = 0;i < V;i++) {
            for(auto it : graph[i]) {
                adj_rev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i = 0;i < V;i++) {
            //reversed indegree==0 ->terminal
            //normal outdegree == 0
            if(indegree[i] == 0 ) {
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto& adj_nodes : adj_rev[node] ) {
                indegree[adj_nodes]--;
                if(indegree[adj_nodes] == 0) {
                    q.push(adj_nodes);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

        //TC : O(V + E)
        //SC : O(V)

        
    }
};