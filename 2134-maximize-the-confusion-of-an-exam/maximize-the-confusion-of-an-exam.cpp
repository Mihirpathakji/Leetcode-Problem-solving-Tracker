class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.length();

        //Case1 : Achiving the Maximum possible consecutives T by converting all possible F to T.

        int i = 0;
        int j = 0;

        //Converting all possible F to T.We need a false count to track,whether is it possible to make that false to true.
        
        int false_count = 0;
        int max_len1 = INT_MIN;

        while(j < n)
        {
            if(answerKey[j] == 'F') {
                false_count++;
            }

            //Invalid window shrink.
            while(false_count > k)
            {   
                if(answerKey[i] == 'F')
                {
                    false_count--;
                }
                i++;
            }

            max_len1 = max(max_len1,j-i+1);//there are j-i+1 trues.
            j++;
        }   


        int max_len2 = INT_MIN;

        i = 0;
        j = 0;

        //Case2 : Converting all possible T to F.We need a true count to track if that true is a valid one to be removed with our possible k operations.

        int true_count = 0;

        while(j < n)
        {
            if(answerKey[j] == 'T')
            {
                true_count++;
            }

            //Invalid window shrink.
            while(true_count > k)
            {
                //we cannot convert that true_count th true to false.Lets make the false which was on the left most to true , to use that operation on the righmost rather.

                if(answerKey[i] == 'T')
                {
                    true_count--;
                }
                i++;
            }

            max_len2 = max(max_len2,j-i+1);//there are j-i+1 false.
            j++;
        }

        return max(max_len1,max_len2);
        
    }
};