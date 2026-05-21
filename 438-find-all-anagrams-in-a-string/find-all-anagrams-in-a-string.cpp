class Solution {
public:

    bool allZeroes(vector<int>Counter)
    {   
        for(int i =0; i < Counter.size();i++)
        {
            if(Counter[i]!=0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

      vector<int>Counter(26,0);
      for(int i = 0 ; i< p.size();i++)
      {
        Counter[p[i]-'a']++;
      }  

    // Two Pointer for the sliding window:

    int i = 0;
    int j = 0;     

    int n = s.size();
    int k = p.size();
    vector<int>ans;

    while(j < n)
    {
        //j indexed is always in our Window.
        Counter[s[j]-'a']--;

        if(j - i + 1 == k)
        {
            if(allZeroes(Counter))
            {
                ans.push_back(i);
            }
                Counter[s[i]-'a']++;
                //We are moving that i to one step Ahead.i.e that i is now no longer in our subarray.

                i++;
        }
        j++;
    }
    return ans;


        //TC : O(n)
        //SC : O(1)
    }
};