class Solution {
public:
   
    int totalFruit(vector<int>& fruits) {

        //Maximum size of the sliding window with 2 distinct characters.

        int n = fruits.size();
        unordered_map<int,int>mp;

        int i = 0;
        int j = 0;
        int ans = INT_MIN;

        while(j < n)
        {
            
            mp[fruits[j]]++;//1

            while(mp.size() > 2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }

            if(mp.size()==2)
            {
                ans = max(ans,j-i+1);
            }

            j++;//1
        }

        if(ans == INT_MIN)
        {
            ans = fruits.size();
        }
        return ans;

    }
};