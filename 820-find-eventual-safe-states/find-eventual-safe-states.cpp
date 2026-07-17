//JAY SHREE RAM.
class Solution {
public:

    bool dfs(int start,vector<int>&visited,vector<int>&Same_Path_visited,vector<vector<int>>&graph,vector<int>&safe_node) {

        visited[start] = 1;
        Same_Path_visited[start] = 1;

        for(int &v : graph[start] ) {

            if(visited[v] == 0) {

                if( dfs(v,visited,Same_Path_visited,graph,safe_node) == true ) {
                    safe_node[v] = 0;
                    return true;
                }
            }
            else {
                if(Same_Path_visited[v] == 1) {
                    safe_node[v] = 0;
                    return true;
                }
            }
        }

        safe_node[start] = 1;

        Same_Path_visited[start] = 0;

        return false;

    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>Same_Path_visited(n,0);  
        vector<int>safe_node(n,0);

        for(int i = 0;i < n;i++) {
            if(visited[i] == 0) {
                dfs(i,visited,Same_Path_visited,graph,safe_node);
            }
        }    

        vector<int>ans;

        for(int i = 0;i < n;i++) {
            if(safe_node[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;

        //TC : O(V + E)
        //SC : O(V)
        
    }
};