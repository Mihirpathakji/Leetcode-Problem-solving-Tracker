//JAY SHREE RAM.
class Solution {
public:

    bool dfs(int start,vector<int>&visited,vector<int>&Same_Path_visited,vector<vector<int>>&graph,vector<int>&safe_node) {

        visited[start] = 1;
        Same_Path_visited[start] = 1;

        for(int &v : graph[start]) {

            if(visited[v] == 0) {

                if(dfs(v,visited,Same_Path_visited,graph,safe_node)) {
                    safe_node[v] = 0;//this v contributes somehow to cycle ,cant contirbute to a safe node.
                    return true;
                }
            }
            else {
                if(Same_Path_visited[v] == 1) {
                    //cycle detected.
                    safe_node[v] = 0;//this v contributes to a cycle , does not contribute to a safe node.
                    return true;
                }
            }
        }

        safe_node[start] = 1;//It is a safe_node it is not connected with any kind of cycle.
        Same_Path_visited[start] = 0;
        return false;//since cycle does not detected.

    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        //Just identify the No.of nodes which are in any cycle ,and number of nodes which are approaching a cylce.Except these all are safe nodes.Because except these node all nodes will endup at an temrinal nodes.       

        //To determine whether the nodes are part of cycle or not.We can use cycle detection of directed graph.

        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>Same_Path_visited(n,0);  
        vector<int>safe_node(n,0);//Tracks whether the ith node is safe node or node.If the ith node is safe node than we marked safe_node[i] = 1 else marked as 0.

        for(int i = 0;i < n;i++) {
            if(visited[i] == 0) {
                dfs(i,visited,Same_Path_visited,graph,safe_node);//Run cycle detection for every unvisited node.
            }
        }   

        vector<int>ans;

        for(int i = 0;i < n;i++) {
            if(safe_node[i] == 1) {
                ans.push_back(i);//these nodes does not contribute to a cycle.
            }
        }

        return ans;

        //TC : O(V + E)
        //SC : O(V)
        
    }
};