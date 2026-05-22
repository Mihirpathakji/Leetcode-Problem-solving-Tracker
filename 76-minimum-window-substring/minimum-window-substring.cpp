class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        
        unordered_map<char,int>mp;
        for(int i = 0 ; i < t.length(); i++)
        {
            mp[t[i]]++;
        }

        int Required_count = t.length();
        int min_possible_window_size = INT_MAX;

        int i = 0,j = 0;
        int start_index = 0;
        while(j < n)
        {
            if(Required_count > 0 && mp[s[j]] >= 1)
            {
                //i.e we needed that jth indexed element and we get it into our window.Since jth element will always be in our window.  
                
                Required_count--;
            }

            mp[s[j]]--;//jth element is in window.

            while(Required_count == 0)
            {
                //i.e Our Window contains all the elements of the t.

                //Track the size of it to the minimal.
                int current_window_size = j-i+1;

                if(current_window_size < min_possible_window_size)
                {
                    min_possible_window_size = current_window_size;
                    start_index = i;
                }

                mp[s[i]]++;

                //Leaving that character. Now if the frequency of that char in map > 0 i.e it is was needed to form substring of t and we dont have it.

                //i.e

                if(mp[s[i]] >= 1)
                {
                    //i.e is in map but is not in our window.But it is needed to form substring of t 

                    Required_count++; 
                }

                i++;

            }
            j++;

        }

        if(min_possible_window_size == INT_MAX)
        {
            return "";
        }
        
        return s.substr(start_index,min_possible_window_size);

        //TC : O(n)
        //SC : O(t)
        
    }
};