class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length();    
        vector<int>diff(n,0);

        //Calculating the effective change that has to be done at each indices.

        //Applying Difference array technique for Multiple range operation.

        for(int i = 0; i < shifts.size();i++)
        {   
            int start_index = shifts[i][0];
            int end_index = shifts[i][1];
            int value = shifts[i][2];

            if(!value)
            {
                value = -1;
            }

            diff[start_index] += value;

            if(end_index + 1 < n)
            diff[end_index + 1] -= value;

        }        

        //Applied both operations to all Multiple Ranges. Now take cumulative sum of diff(Prefix sum).

        for(int i = 1;i < n;i++)
        {
            diff[i] = (diff[i]+diff[i-1]);
        }    

        //diff[] contains the "effective changes" to each of the index.

        for(int i = 0; i < n; i++)
        {
            //Important steps : 

            //STEP1:
            //difference can be in [-10^5,10^5].
            //Brought it in the range of [-26,26] by % 26.%26 Broughts it in range of [-26,26] taking that diff[i] can be -be.

            diff[i] = diff[i] % 26;

            //STEP2:But still diff[i] can be a -ve number in range [-26,26]
            //But we cannot add -ve difference since 'a' + -ve will go to the characters behind 'a' which are not the small case latin letters.Hence if it is -ve than we need to make it +ve.->Add 26 for that.

            diff[i] = diff[i] + 26;

            int value_in_range_26 = s[i]-'a';

            //Now added diff below in  >=0  and also in range [0,26].

            //Now since both values_in_range_of
            
            s[i] = (value_in_range_26 + diff[i])%26 + 'a';
           
            //+'a' to convert the final obtained integer to it's character value.

        }
        
        return s;

    }
};