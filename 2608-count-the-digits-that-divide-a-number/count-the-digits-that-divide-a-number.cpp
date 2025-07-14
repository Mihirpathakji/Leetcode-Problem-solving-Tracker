class Solution {
public:
    int countDigits(int num) {

    int temp =num;    
    int count = 0;    
    int ans = 0;
    int r ;
    while(num!=0){
        
        r = num % 10;  // 1  2   1

        ans = r; //if we do ans = ans + r then in the second iteration it will take value of ans stored in the first iteration ans = 8 + 4  but we actually want only r in ans // 1  2   1

        if(temp % ans == 0){
            count ++;    // 1 2  3 4     // 1
            
        }

        num /= 10;   // 124 12  1 0 // 12  1 0

    }

    return count;

    }
};