class Solution {
public:

    void bfs(int& start,int& min_dist,queue<int>& q,vector<bool>&visited,unordered_map<int,vector<pair<int,int>>>& adj_list ) {

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {

            int u = q.front();   
            q.pop();

            //Traverse in the Neighbours of the start.

            for(auto &v : adj_list[u]) {

                if(visited[v.first] == false) {
                    visited[v.first] = true;
                    q.push(v.first);
                }

                min_dist = min(min_dist,v.second);
            }

        }

    }


    int minScore(int n, vector<vector<int>>& roads) {
        
        int m = roads.size();//4
        unordered_map<int,vector<pair<int,int>>>adj_list(n+1);

        for(int i = 0;i < m;i++) {
            
            int u = roads[i][0];
            int v = roads[i][1];
            int weight = roads[i][2];

            adj_list[u].push_back({v,weight});  
            
            adj_list[v].push_back({u,weight});
        }

        vector<bool>visited(n+1,false);
        queue<int>q;

        int start = 1;//bfs only for 1 as start.

        int min_dist = INT_MAX; 

        bfs(start,min_dist,q,visited,adj_list);

        return min_dist;

        //TC : O(m) + O(n + 2*e)
        //SC : O(n)

    }
};