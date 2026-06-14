class Solution {
public:
    int getLength(vector<int>& nums) {

        int n = nums.size();
        int max_len = INT_MIN;
        //Brute Force for every subarray: 

        for(int i = 0; i < n; i++)
        {
            unordered_map<int,int>mp;

            unordered_map<int,int>frequency_count;//stores the frequency and number of elements with that frequency.

            for(int j = i;j < n;j++)
            {
                int old_freq = mp[nums[j]];
                int new_freq = old_freq + 1; 

                mp[nums[j]] = new_freq;   

                if(old_freq > 0)
                {
                    frequency_count[old_freq]--;//Number of the elements with that old frequency decreases.
                    if(frequency_count[old_freq] == 0)
                    {
                        frequency_count.erase(old_freq);
                    }
                }

                frequency_count[new_freq]++;

                //If there are only 1 distinct elements.

                if(mp.size() == 1)
                {
                    max_len = max(max_len,j-i+1);
                }

                //More than 1 distinct but each has frequency f or 2*f.

                //Number of distinct frequnecies should be exactly 2
                else if(frequency_count.size() == 2)
                {
                    //There are only 2 distinct keys i.e frequency.

                    auto it =  frequency_count.begin();//In Map ->The iterators acts like pointers.Hence,must use '->'   *. is not allowed to access their data. 

                    int first = (it->first);//1st frequency ->f or 2*f
                   
                    it++;
                    int second = it->first;

                    if(first == 2*second || second ==2*first)
                    {
                        max_len = max(max_len,j-i+1);
                    }
                }
            }            

        }

        return max_len;

        //TC : O(n^2)
        //SC : O(n)
        
    }
};