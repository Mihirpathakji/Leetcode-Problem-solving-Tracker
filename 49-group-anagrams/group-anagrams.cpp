class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string>another_ans = strs;//O(n*k)
        for(int i = 0;i<another_ans.size();i++)
        {
            sort(another_ans[i].begin(),another_ans[i].end());
        }

        //TC : O(n*klogk)
        unordered_map<string,vector<int>>mp;
        for(int i = 0; i< another_ans.size(); i++)
        {
            mp[another_ans[i]].push_back(i);
        }

        vector<vector<string>>final_ans;
        for(auto it : mp)
        {
            vector<string>to_be_pushed;
            for(int i = 0; i < it.second.size() ; i++)
            {
                to_be_pushed.push_back(strs[it.second[i]]);
            }
            final_ans.push_back(to_be_pushed);

        }

        return final_ans;
        //TC : O (n*klogk)
        //SC : O(strs.size())

    }
};