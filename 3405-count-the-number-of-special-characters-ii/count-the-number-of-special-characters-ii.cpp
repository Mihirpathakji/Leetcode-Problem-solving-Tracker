class Solution {
public:
    int numberOfSpecialChars(string word) {

        //For the smaller case elements just push their last index.Since,if their last index is before the first occurance of the Capital of it i.e every occurance of the small_case characters is before the first occurance of the upper case of it.

        unordered_map<char,int>small_upper_both;

        //inserting the last indexes of the small_case letters.

        //Backward loop.

        for(int i = word.size()-1;i >= 0 ;i--)
        {   
            //small case : 
            if(word[i] >= 95 && word[i] <= 122 && (small_upper_both.find(word[i]) == small_upper_both.end()))
            {
                small_upper_both[word[i]] =  i;//last index.
            }
        }

        //Inserting First index Upper case letters into map.

        //Forward loop : 

        for(int i = 0; i< word.size(); i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z' && small_upper_both.find(word[i]) == small_upper_both.end())
            {
                small_upper_both[word[i]] = i;
            }
        }

        int count = 0;
        for(auto it : small_upper_both)
        {
            //it = {key,value}. it,first = key, it.second = value.
            if(it.first >= 'A' && it.first <= 'Z')
            {
                if(small_upper_both.find(it.first+32)!=small_upper_both.end() && small_upper_both[it.first + 32] < small_upper_both[it.first])
                {
                    count++;//
                }
            }
        }
        return count;

    }
};