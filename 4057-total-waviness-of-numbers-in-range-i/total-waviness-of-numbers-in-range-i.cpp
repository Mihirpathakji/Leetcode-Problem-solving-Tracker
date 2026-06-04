class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int a = num1;
        int b = num2;

        int c = a;
        int peaks = 0;
        int valleys = 0;

        while(c <= b)
        {
            //Extract all digits of c.
            int d = c;//120 121  122
            vector<int>temp;
            while(d > 0)
            {   
                temp.push_back(d%10);
                d/=10;
            } 
            
            reverse(temp.begin(),temp.end());//[021]->[120]->[121]

            for(int i = 0 ; i < temp.size(); i++)
            {
                if( (i!=0 && i!=temp.size()-1 )&& temp[i] > temp[i+1] && temp[i] > temp[i-1])
                {
                    peaks++;//12
                }
                if( (i!=0 && i!=temp.size()-1 ) && temp[i] < temp[i+1] && temp[i] < temp[i-1])
                {
                    valleys++;
                }
            }
            c++;//122
        }

        return peaks + valleys;

        //TC : O(n*logn)
        //SC : O(logn)
        
    }
};