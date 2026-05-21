class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<string,int>mp;

        // 1
        // 10
        // 100
        // 1000
        // 2
        // 20
        // 200

        for(int i=0; i<arr1.size(); i++) {
            string temp = to_string(arr1[i]);
            for(int j=0; j<=temp.size(); j++) {
                mp[temp.substr(0,j)] = 1;
            }
        }

        int maxi = 0;
        for(int i=0; i<arr2.size(); i++) {
            string temp = to_string(arr2[i]);
            for(int j=0; j<=temp.size(); j++) {
                if(mp.find(temp.substr(0,j)) != mp.end()) {
                    maxi = max(maxi,j);
                }
            }
        }

        return maxi;


    }
};