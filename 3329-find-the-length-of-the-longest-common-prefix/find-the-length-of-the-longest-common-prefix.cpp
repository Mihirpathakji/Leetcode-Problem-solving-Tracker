class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int ans = 0;//minimum possible length of the common prefix.
        unordered_map<string,int>mp;

        //Finding if the prefix of the any arr1[i] exists in arr2[] or not.

        for(int i = 0 ; i < arr1.size(); i++)
        {
            string temp = to_string(arr1[i]);
            //Hash All the Prefixes(0,j) where j  = 0 to size -1. of the arr1[i].
            for(int j = 0;j <= temp.size(); j++)
            {
                mp[temp.substr(0,j)]++;
            }
        }

        for(int i = 0 ; i< arr2.size() ; i++)
        {
            string temp = to_string(arr2[i]);

            for(int j = 0 ; j <= temp.size(); j++)
            {
                if(mp.find(temp.substr(0,j))!= mp.end())
                {
                    ans = max(ans,j);
                }
            }
        }

        return ans;

        //TC :O() 
        //SC :O()

    }
};