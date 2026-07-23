class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        //Order of the nums element does not matters.What matter is only their size == n.

        int n = nums.size();
        if(n== 1 || n==2) {
            return n;
        }

        //ans is the Nearest power of the 2 which exceeds nums.size();
        
        int ans = 1;

        while(ans <= n) {
            ans*=2;
        }

        return ans;

        
    }
};