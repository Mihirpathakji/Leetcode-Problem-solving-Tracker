//JAY SHREE RAM
class Solution {
public:

    void dfs(int start,int parent,vector<int>& color,vector<vector<int>>&graph,bool& bipartite) {

        //dfs is a Recursive one.You will need to return boolean value at every step.

        if( parent == -1 || color[parent] == 1 ) {
            color[start] = 0;
        }
        else {
            color[start] = 1;
        }

        for(auto v : graph[start]) {

            if(color[v] == -1) {
                dfs(v,start,color,graph,bipartite);
            }
            else {
                if(color[v] == color[start]) {
                    bipartite = false;
                    return;
                }
            }
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {

        //through dfs :
        //No two adjacent nodes should have the same color.
        int n = graph.size();

        vector<int>color(n,-1);
        bool bipartite = true;
        int parent = -1;

        for(int i = 0;i < n;i++) {
            if(color[i] == -1) {
                dfs(i,parent,color,graph,bipartite);
                if(bipartite == false) {
                    return false;
                }
            }
        }

        return true;

        //TC : O(V + 2*E)
        //SC : O(V)
        
    }
};