class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        //if i get the ans i would minimize it.

        int n = letters.size();
        int low = 0;
        int high = n-1;

        char ans = letters[0];

        while(low <= high)
        {
            int mid = low +  (high-low)/2;

            if(letters[mid] > target) {
                //search for the smallest.
                ans = letters[mid];
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }

        return ans;
        
        //TC : O(logn)
        //SC : O(1)
    }
};