//JAY SHREE RAM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        vector<int>indegree(V,0); 
        unordered_map<int,vector<int>>adj_list;

        for(vector<int>& edge : prerequisites ) {

            int u = edge[0];
            int v = edge[1];
            indegree[u]++;

            adj_list[v].push_back(u);

        }

        vector<int>ans;

        queue<int>q;

        for(int i = 0;i < V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto& v  : adj_list[node] ) {

                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }

        }

        if(ans.size()!=V) {
            return {};
        }
        
        return ans;
        
        //TC : O(V + E)
        //SC : O(V)
    }
};