class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

       vector<string>another_ans = strs;

       for(int i = 0;i < another_ans.size();i++)
       {
            sort(another_ans[i].begin(),another_ans[i].end());
       } 


        unordered_map<string,vector<int>>mp;
        for(int i = 0;i<another_ans.size();i++)
        {
            mp[another_ans[i]].push_back(i);//aet -> 0 1 3 
            //ant -> 2  4
            //5
        }

        vector<vector<string>>final_ans;

        for(auto it : mp)
        {
            vector<string> to_be_push;
            for(int i = 0; i< it.second.size();i++)
            {
                to_be_push.push_back(strs[it.second[i]]);
            }

            final_ans.push_back(to_be_push);
        }

        return final_ans;    

    }
};