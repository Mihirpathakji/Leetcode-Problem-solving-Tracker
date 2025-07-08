class Solution {
public:

    bool eatbananas(vector<int>&piles,int h,int mid){

        int n = piles.size();
        long long int totalhours = 0; 

        for(int i =0; i<n;i++){
            piles[i]/mid <= h;
             totalhours += ceil((double)piles[i]/(double)mid); // Nearest longest integer to   the given double    
        }
            return totalhours <=h;//it will return true or false and accordingly ans will store the mid, at the end after the function call we have return ans so ans or the k will be returned

     }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int start = 1;//Minimum number of the bananas per hours 
        int end = *max_element(piles.begin(),piles.end());
        int ans =-1;

        while(start<=end){

            int mid = start + (end -start)/2;

            if(eatbananas(piles,h,mid)){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid + 1;
            } 
       }      
       return ans;

       
    // Time complexity :- log(max of all the piles element) *n

    }
};