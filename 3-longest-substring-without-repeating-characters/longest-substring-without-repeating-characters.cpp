class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
    unordered_set<char>st(s.begin(),s.end());//' '

    if(st.size() == 1)
    {
        //i.e only one  space type character was there.

        return 1;//"    "->4 
    }

    unordered_map<char,int>mp;

    long long  maximum_len = 0;
    long long  current_count = 0;

    //mp.find()-> If the element is already present in the map -> mp.find() returns an iterator which points to that element . If it is not present in the map  -> than it will return mp.end() 
    
    //O(n^2).
    
    for(int i = 0; i< (int)s.size();i++)
    {
        for(int j = i; j <(int) s.size() ; j++)
        {
            if(mp.find(s[j])!=mp.end())
            {       
                // element is present in the map.
                //update the current len.
                maximum_len = max(maximum_len,current_count);
                current_count = 0;
                mp.erase(mp.begin(),mp.end());
                break;
            }
            else
            {
                mp[s[j]]++;//1 
                current_count++;//1  9
            }
        }
    }

    if(!mp.size())
    {
        maximum_len = max(maximum_len,current_count);
    }

    return maximum_len;
    
    }
};

//SC : O(n)
//TC : O(n^3) approx n^2;