class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int>mp;
        long long limit = 0;
        for(int i =0;i < n;i++) {
            mp[nums[i]]++;
            limit += nums[i];
        }

        long long max_sum = nums[0];

        int j = 1;
       
        while(j < n && nums[j] ==  nums[j-1] + 1) { 
            max_sum += nums[j];
            j++;
        }


        for(int i = 1;i <= limit+1 ;i++) {
            if(mp.find(i) == mp.end() && i >= max_sum) {
                return i;
            }
        }

        return -1;
        
    }
};