class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int countdigits=0;
        int countnumbers=0;
        int count=0;
        for(int i =0;i<nums.size();i++){
            countdigits=0;
            while(nums[i]!=0){
                countdigits++;
                nums[i]/=10;
           }
            if(countdigits%2==0)
               countnumbers++;   
        }
          return countnumbers;
    }
};