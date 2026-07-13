class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high)  {

        string universal = "123456789";
        string l1 = to_string(low);//TC : O(1) here.//3. 1000
        string l2 = to_string(high);//3 13000

        vector<int>result;

        int size_l1 = l1.length();//3 // 4
        int size_l2 = l2.length();//3 // 5

        for(int i = size_l1;i <= size_l2;i++) {

            for(int j = 0;j <= 9-i;j++) {

                string ans = universal.substr(j,i);//1234  2345 3456 4567 5678 6789 12345 
                int number = stoi(ans);//345 // 1234  2345 3456 4567 5678 6789 6789 12345 

                //The number must lies in between the boundaries inorder to be in interval.7

                if(number >= low && number <= high) {
                    result.push_back(number);//123 234 // 1234 2345 3456 4567 5678 6789 12345
                }
                else if(number > high){
                    break;
                }
            } 
        }

        return result;

        //TC : O(1) 
        //SC : O(1).There are only 36 Sequential digits from 10 to 1e9.
        
    }
};