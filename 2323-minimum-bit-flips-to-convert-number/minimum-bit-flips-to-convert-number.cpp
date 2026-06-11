class Solution {
public:
    int minBitFlips(int start, int goal) {

        //Convert start and goal to binary.
        
        vector<int>start_binary;
        while(start > 0)
        {
            int remainder = start%2;
            start_binary.push_back(remainder);
            start = start >> 1;
        }

        vector<int>goal_binary;
        while(goal > 0)
        {
            int remainder = goal%2;
            goal_binary.push_back(remainder);
            goal = goal >> 1;
        }

        if(start_binary.size() > goal_binary.size())
        {
            while(goal_binary.size()!=start_binary.size())
            {
                goal_binary.push_back(0);//4 5 
            }
        }
        
        else if(goal_binary.size() > start_binary.size())
        {
            while(start_binary.size()!=goal_binary.size())
            {
                start_binary.push_back(0);
            }
        }

        reverse(start_binary.begin(),start_binary.end());   
        reverse(goal_binary.begin(),goal_binary.end());

        int min_flips = 0;

        for(int i = 0 ;i < goal_binary.size();i++)
        {
            if( (goal_binary[i] ^ start_binary[i]) == 1)
            {   
                min_flips++;
            }
        }

        return min_flips;

        //TC : O(max(log(start),log(end)))
        //SC : O(2*(max(log(start),log(end)))
        
    }
};