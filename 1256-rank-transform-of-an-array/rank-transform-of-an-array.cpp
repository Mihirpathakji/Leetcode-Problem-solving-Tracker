class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int>arr2 = arr;
        sort(arr2.begin(),arr2.end());
        int counter = 1;
        int n = arr2.size();
        unordered_map<int,int>mp;

        for(int  i = 0;i < n;i++) {
            if(mp.find(arr2[i]) == mp.end()) {
                mp[arr2[i]] = counter;
                counter++;
            }
        }

        vector<int>ans(n,0);
        for(int i = 0;i < n;i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
        
    }
};