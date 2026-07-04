class Solution {
public:

    void dfs(int& u,unordered_map<int,vector<int>>& adj_list,vector<bool>& visited,vector<int>& baseTime,vector<long long>& finish_time) {

        visited[u] = true;

        for(auto &v : adj_list[u]) {
            if(visited[v] == false) {
                dfs(v,adj_list,visited,baseTime,finish_time);
            }
        }


        //Leaf node : No elements in the adjacency list.
        if(adj_list[u].empty()) {
            finish_time[u] = baseTime[u];
        }
        else {
            long long maxi = LLONG_MIN;
            long long mini = LLONG_MAX;

            //finish time for this parent node having atleast one children is : max + max -min + basetime[i].Where max is maximum finish time among all it' childrens.

            //Calculating max , min : maximum finishtime and minimum finishtime among it's children.

            for(auto &child : adj_list[u]) {
                maxi = max(maxi,finish_time[child]);
                mini = min(mini,finish_time[child]);
            }

            finish_time[u] = 2*maxi - mini + baseTime[u];
        }

    }


    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        int m = edges.size();
        unordered_map<int,vector<int>>adj_list(n);
        //Parent->{All childs}.

        for(int i = 0;i < m;i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
        }

        vector<long long>finish_time(n);
        vector<bool>visited(n,false);
        int root = 0;
        dfs(root,adj_list,visited,baseTime,finish_time);

        return finish_time[root];

        //TC : O(n + 2*e)
        //SC : O(n)
        
    }
};