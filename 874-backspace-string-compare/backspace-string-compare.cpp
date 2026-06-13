class Solution {
public:

    bool backspaceCompare(string s, string t) {

        for(int i = 0;i < s.size(); i++)
        {//s.size()==5
            if(s[i] == '#')
            {
                s.erase(s.begin()+i);//erasing a single element from the string.Than you need to give the iterator of that single element. 

                if(i!=0)
                {
                    s.erase(s.begin()+i-1);//O(N)
                    i = i-2;//-1
                }
                else
                {
                    i--;//-1
                }
            }   
            //0
        }
        //O(N^2)

        for(int i = 0;i < t.size(); i++)
        {
            if(t[i] == '#')
            {
                t.erase(t.begin()+i);//erasing a single element from the string.Than you need to give the iterator of that single element. 

                if(i!=0)
                {
                    t.erase(t.begin()+i-1);//O(N)
                    i = i-2;//-1
                }
                else
                {
                    i--;//-1 -1
                }
            }   //i=0 0
        }
        //O(N^2)

        //Removing single character from string ->s.erase(iterator) == s.erase(s.begin()+i); 

        return s == t;

        //TC : O(s^2 + t^2).Since .erase in a string takes O(n)tc.Since all the string elements "Shifts" to the left on one deletion.

        //SC : O(1)

    }
};