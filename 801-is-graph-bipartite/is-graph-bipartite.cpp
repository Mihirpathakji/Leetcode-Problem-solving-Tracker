//JAY SHREE RAM.

class Solution {
public:

    bool bfs(int start,queue<int>q,vector<int>&color,vector<vector<int>>&graph) {

        q.push(start);
        color[start] = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int v : graph[node] ) {

                if(color[v] == -1) {
                    if(color[node] == 0) {
                        color[v] = 1;
                    }
                    else {
                        color[v] = 0;
                    }
                    q.push(v);
                }
                else {
                    if(color[node] == color[v]) {
                        return false;
                    }
                }
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();      
        vector<int>color(n,-1);
        queue<int>q;

        for(int i = 0;i < n;i++) {
            if(color[i] == -1) {
                if(!bfs(i,q,color,graph)) {
                    return false;
                }
            }
        }

        return true;

        //TC : O(V + 2*E)
        //SC : O(V)

    }
};