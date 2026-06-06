class Solution {
public:

    bool all_Zeroes_of_Counter(vector<int>&Counter)
    {
        for(int i = 0 ;i < Counter.size(); i++)
        {
            if(Counter[i] != 0)
            {
                return false;
            }
        }   
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        vector<int>Counter(26,0);
        int i = 0;
        int j = 0;
        int k = s1.size();

        //Hashing s1 : 
        
        for(int i = 0 ; i < s1.size();i++)
        {
            Counter[s1[i]-'a'] += 1 ;
        }

        while(j < s2.size())
        {
            Counter[s2[j] -'a'] -= 1;

            if(j-i+1 == k)
            {
                if(all_Zeroes_of_Counter(Counter))
                {
                    return true;
                }
                Counter[s2[i] -'a'] += 1;                
                i++;
            }
            
            j++;//1 2
        }
        
        return false;
        
    }
};