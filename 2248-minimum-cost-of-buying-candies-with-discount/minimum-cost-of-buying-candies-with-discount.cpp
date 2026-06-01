class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.rbegin(),cost.rend());//[9,7,6,5,2,2]
        int min_cost = 0;

        int blocks = 0;

        for(int i = 0 ; i< cost.size(); i++)
        {
            if(blocks == 2)
            {
                blocks = 0;
                continue;
            }

            blocks++;//12 1 2
            min_cost += cost[i];//9 16 21 23
        }

        return min_cost;

        
    }
};