class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        int n = matches.size();

        // To track whether a particular player has played atleast one match or not.

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0;i < n;i++) {
    
            maxi = max(maxi,matches[i][0]);
            maxi = max(maxi,matches[i][1]);

            mini = min(mini,matches[i][0]);
            mini = min(mini,matches[i][1]);
        
        }

        vector<int>lose(maxi+1,0);
        vector<bool>played(maxi+1,false);
        for(int i = 0;i < n;i++) {
            
            int losser = matches[i][1];
            lose[losser]++;

             int player1 = matches[i][0];
            played[player1] = true;

            int player2 = matches[i][1];
            played[player2] = true;
    
        }

        vector<vector<int>>ans(2);

        for(int i = 0;i < lose.size();i++) {
            if(lose[i] == 0 && played[i] == true) {
                ans[0].push_back(i);
            }
            else if(lose[i] == 1 && played[i] == true) {
                ans[1].push_back(i);
            }
        }

        for(int i = 0;i < ans.size();i++) {
            sort(ans[i].begin(),ans[i].end());
        }

        return ans; 

        //TC : O(n^2logn)
        //SC : O(1e5)

    }
};