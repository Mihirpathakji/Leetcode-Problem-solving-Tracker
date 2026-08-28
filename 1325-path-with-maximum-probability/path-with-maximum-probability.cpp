class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        //Adjacency list : 

        unordered_map<int,vector<pair<int,double>>>mp;//u -> {v,probability_sucess_u_v}.

        for(int i = 0;i < edges.size();i++) {

            int start = edges[i][0];//0 1 0 
            int end = edges[i][1];//1 2 2
            double success_probab = succProb[i];//0.5 0.5 0.2

            mp[start].push_back({end,success_probab});//int,{{},{}}. 
            mp[end].push_back({start,success_probab});

        }

        vector<int>visited(n,0);

        vector<double>max_probab(n,0);
        
        max_probab[start_node] = 1.0000;

        priority_queue<pair<double,int>>pq;//Max Heap.//{Sucess_Probab,node}.//success probab of the node v from the source node.

        pq.push({1.0000,start_node});
       
        while(!pq.empty()) {

            int u = pq.top().second;//0. 1. 2.

            pq.pop();

            if(visited[u] == 1) {
                continue;
            }

            visited[u] = 1;//1.

            for(auto adj_vec : mp[u]) {
 
                int v = adj_vec.first;//1 2 2.1 0.
                double weight_probab = adj_vec.second;//0.5. // 0.5.

                if(visited[v] == 1) {
                    continue;
                }

                if(max_probab[v] < max_probab[u]*weight_probab) {
                    max_probab[v] = max_probab[u]*weight_probab;//0.5 0.2
                    pq.push({max_probab[v],v});
                }
            }

        }

        return max_probab[end_node];
        
    }
};