class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high)  {

        string universal = "123456789";
        string l1 = to_string(low);//TC : O(1) here.//3.
        string l2 = to_string(high);//3 

        vector<int>result;

        int size_l1 = l1.length();//3
        int size_l2 = l2.length();//3 

        for(int i = size_l1;i <= size_l2;i++) {

            for(int j = 0;j <= 9-i;j++) {

                string ans = universal.substr(j,i);
                int number = stoi(ans);//345

                //The number must lies in between the boundaries inorder to be in interval.

                if(number >= low && number <= high) {
                    result.push_back(number);//123 234 
                }
            }
        }

        return result;

        //TC : O(1) 
        //SC : O(1).There are only 36 Sequential digits from 10 to 1e9.
        
    }
};