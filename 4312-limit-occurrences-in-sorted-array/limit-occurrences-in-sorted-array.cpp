class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        map<int,int>mp;

        for(int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }//logn

        vector<int>ans;
        for(auto &it : mp)
        {
            //it ->pair ->{no.,occurances}.
            if(it.second >= k)
            {
                //it is just the copy of the key value pairs.
                it.second = k;
            }
        }

        for(auto it : mp)
        {
            while(it.second--)
            {
                ans.push_back(it.first);//[1 1 2 2 3]
            }
        }

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};