class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        //One - Pass Sliding window :

        //Approach : For all possible windows , i will convert all the minimum frequency chars to max frequency chars , provided that No. of operations required to convert that min frequency char to max frequency char is in range of [0,k].

        //Choosing always the min_frequency element to convert into the maxfrequency element is optimal since it uses least number of operations -> i.e more probable that operations required for this will be in range of [0,k].

        int n  = answerKey.length();
        int i = 0;
        int j = 0;
        int true_count = 0;
        int false_count = 0;
        int max_len = INT_MIN;

        while(j < n)
        {
            if(answerKey[j] == 'T')
            {
                true_count++;
            }
            else
            {
                false_count++;
            }

            //It is not possible to convert even the minimum frequency element into the maximum frequency element with the given number of operations k.->Invalid window shrink.
 
            while(min(true_count,false_count) > k)
            {
                if(answerKey[i] == 'T')
                {
                    true_count--;
                }
                else
                {
                    false_count--;
                }

                i++;
            }

            max_len = max(max_len,j-i+1);   
            j++;

        }

        return max_len;

        //TC : O(n)
        //SC : O(1) 

        
    }
};