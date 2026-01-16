class Solution {
public:
    string largestEven(string s) {
        
        while(true)
        {   
            if(!s.size())
            {
                break;
            }
            if(s.back() == '2')
            {
                return s;
            }
            else
            {
                s.pop_back();
            }
        }
        return "";

        //TC:O(n)
        //SC:O(1)

    }
};