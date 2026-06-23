class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        //take every possible Prefix substring :-
        
        int n = s.length();//6

        for(int j = 0;j < n-1;j++)
        {
            string temp = s.substr(0,j+1);//ab
            string making = temp;

            while(making.length()<=1e4)
            {
                if(making == s)
                {
                    return true;
                }
                if(making.size() > n)
                {
                    break;
                }
                making += temp;//abab
            }
        }   

        return false;

    }
};