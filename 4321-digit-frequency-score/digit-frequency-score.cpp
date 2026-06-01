class Solution {
public:
    int digitFrequencyScore(int n) {

        unordered_map<int,int>mp;
        while(n!=0)
        {
            long long rem = n % 10;//2 1
            mp[rem]++; //1
            n/=10;
        }

        //mp[1]=1 mp[2]=2

        long long ans = 0;

        for(auto it : mp)
        {
            ans += (it.first*it.second);
        }

        return ans;

    }
};