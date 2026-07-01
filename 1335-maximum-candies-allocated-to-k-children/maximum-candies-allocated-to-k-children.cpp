class Solution {
public:

    bool isAllocationPossible(long long max_candies,long long k,vector<int>& candies) {

        long long childs_satisfied = 0;
        int n = candies.size();
        
        for(int i = 0;i < n;i++) {
            childs_satisfied += candies[i]/max_candies;//1 2 3 
        }

        return childs_satisfied >= k;//T 

    }


    int maximumCandies(vector<int>& candies, long long k) {
        
        int n = candies.size();
        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high-low)/2;//4

            if(isAllocationPossible(mid,k,candies)) {
                ans = mid;//4 
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }    
        
        return ans;

        //TC : O(n*log1e7)
        //SC : O(1)

    }
};