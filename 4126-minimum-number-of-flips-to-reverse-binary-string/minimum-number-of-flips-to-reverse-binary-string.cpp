class Solution {
public:
    int minimumFlips(int n) {

        //convert it to binary:
        string s;
        while(n!=0)
        {
            int r=n%2;//1 or 0 
            s.push_back(r+'0');//111
            n/=2;
        }
        
        string original = s;

        reverse(s.begin(),s.end());//string s gots changed (reversed)
        int unmatch=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=original[i])
            {
                unmatch++;
            }
        }
        return unmatch;
        //TC:O(log2(n))
        //SC:O(log2(n))
    }
};