class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char,int>Capitals;

        for(int i = 0 ; i < word.size(); i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
            {
                if(Capitals.find(word[i]) == Capitals.end())
                {
                    Capitals[word[i]] = i;//2
                }
            }
        }

        unordered_map<char,vector<int>>small_case;
        unordered_set<char>small_case1;

        for(int i = 0; i< word.size(); i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                small_case[word[i]].push_back(i);
            }
        }

        for(int i = 0; i< word.size(); i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                small_case1.insert(word[i]);
            }
        }

        int count = 0;

        for(auto it : small_case1)
        {
            bool flag = false;
            if(Capitals.find(it - 32)!=Capitals.end())
            {
                vector<int>temp = small_case[it];//0,1
                //Checking every_occurance of the small_case is before upper_case
                for(int i = 0 ; i < temp.size(); i++)
                {
                    if(temp[i] >= Capitals[it-32])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    count++;//1
                }
            }
        }
        return count;
    }
};