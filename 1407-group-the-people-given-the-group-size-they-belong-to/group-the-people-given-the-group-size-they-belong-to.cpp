class Solution {
public:
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        int n = groupSizes.size();
        unordered_map<int,vector<int>>mp;

        for(int i = 0;i < n;i++) {
            mp[groupSizes[i]].push_back(i);
        }

        int size = 0;
        for(auto it : mp) {
            size += (ceil((float)it.second.size()/it.first));
        }

        vector<vector<int>>groups(size);//4 
        int i = 0;//0.
        
        for(auto it : mp) {

            int j = 0;//0

            while(j < it.second.size()) {
                
                groups[i].push_back(it.second[j]);// 
                j++;//1 2 3 // 1

                if(groups[i].size() == it.first) {
                    i++;//1 2 
                }
            }

        }

        return groups;

        
    }
};