class Solution {
public:

    bool isAllocationPossible(long long max_candies,long long k,vector<int>& candies) {

        long long childs_satisfied = 0;
        int n = candies.size();
        
        for(int i = 0;i < n;i++) {

            //If each child takes max_candies than no. of child getting satisfied with candies[i] candies : 
            childs_satisfied += (candies[i]/max_candies); 
        }

        return childs_satisfied >= k;

    }

    int maximumCandies(vector<int>& candies, long long k) {
        
        int n = candies.size();
        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high-low)/2;

            if(isAllocationPossible(mid,k,candies)) {
                ans = mid;
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