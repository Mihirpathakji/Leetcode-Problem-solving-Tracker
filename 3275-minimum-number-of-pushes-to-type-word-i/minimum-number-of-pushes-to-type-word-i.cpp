class Solution {
public:
    int minimumPushes(string word) {

        int n = word.size();//all distinct.
        int ans = 0;

        int j = 0;
        int taken = 1;

        while(j < n) {

            if(taken <= 8) {
                ans++;
            }
            else if(taken <=16) {
                ans+=2;
            }
            else if(taken <= 24) {
                ans+=3;
            }
            else {
                ans+=4;
            }

            taken++;//1
            j++;//
        }

        return ans;


        //TC : O(1)
        //SC : O(1)
    
        
    }
};