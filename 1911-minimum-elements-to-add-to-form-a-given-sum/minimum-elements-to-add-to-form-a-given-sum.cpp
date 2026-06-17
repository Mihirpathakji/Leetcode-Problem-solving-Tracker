class Solution {
public:

    int minElements(vector<int>& nums, int limit, int goal) {
 
        int n = nums.size();

        long long total_sum = 0;
        
        for(int i = 0; i< n; i++)
        {
            total_sum += nums[i];
        } 

        //x+y = goal
        //y = goal-x

        long long diff_needed = abs(goal - total_sum);

        //Ceil division of diff_needed and limit : 

        return (diff_needed + limit -1)/limit;
    
        //TC : O(n)
        //SC : O(1)
        
        //O(goal) -> TLE -> There must exists a O(1)->MATH technique ->Ceil division of diff & limits. 

    }
};