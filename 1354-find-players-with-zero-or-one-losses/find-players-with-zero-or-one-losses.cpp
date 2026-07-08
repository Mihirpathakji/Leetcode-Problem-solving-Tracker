class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        int n = matches.size();

        vector<bool>played(1e5+1,false);

        for(int i = 0;i < n;i++) {
            int player1 = matches[i][0];
            played[player1] = true;

            int player2 = matches[i][1];
            played[player2] = true;
        }

        vector<int>lose(1e5+1,0);

        for(int i = 0;i < n;i++) {

            int losser = matches[i][1];

            lose[losser]++;
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

    }
};