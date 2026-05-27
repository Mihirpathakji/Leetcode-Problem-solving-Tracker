class Solution {
public:
    int numberOfSpecialChars(string word) {

    unordered_map<char,bool>small_case;
    unordered_map<char,bool>capitals;
    for(int i = 0 ; i <word.size();  i++)
    {   
        if(word[i] >= 97 && word[i] <= 122)
        {
            small_case[word[i]] = true;
        }
    }        

    int count = 0;
    //Iterating on All Capitals : 
    for(int i = 0 ; i < word.size(); i++)
    {
        if(word[i] >= 65 && word[i] <= 90)
        {//'A'->'a' 65 to 97 
            if(small_case.find((word[i]+32)) != small_case.end() && (capitals.find(word[i]) == capitals.end()) )
            {//this corresponding small_case is also there in the word
                count++;//1 
                capitals[word[i]] = true;
            }
        }
    }

    return count;

    }
};