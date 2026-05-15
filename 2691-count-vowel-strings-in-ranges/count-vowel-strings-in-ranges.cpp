class Solution {
public:

    bool is_vowel(char& ch)
    {
        return ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int>temp1(words.size());

        for(int i = 0 ; i < words.size(); i++)
        {
            string temp = words[i];
            if(is_vowel(temp[0]) && is_vowel(temp[temp.size()-1]))
            {
                temp1[i] = 1;
            }   
            else
            {
                temp1[i] = 0; 
            }
        }
        //temp = [1 0 1 1 1]
        vector<int>prefix(words.size());

        prefix[0] = temp1[0];
        for(int i = 1;i<words.size();i++)
        {
            prefix[i] = prefix[i-1] + temp1[i]; 
        }

        //prefix[] = [1 1 2 3 4]
        vector<int>ans(queries.size());

        for(int i = 0;i < queries.size(); i++)
        {
            vector<int>helper = queries[i];//[0,2] [1,4] [1,1]
            int l = helper[0];//1
            int r = helper[1];//1
            
            if(l == 0)
            {
                ans[i] = prefix[r];//ans[0] = 2 ans[1] = 3 ans[2]=0
            }

            else 
            {// prefix[r] - prefix[l-1]
                ans[i] = prefix[r] - prefix[l-1];//4-1==3 // 1-1 == 0
            }
        }  
        return ans;
    }
};