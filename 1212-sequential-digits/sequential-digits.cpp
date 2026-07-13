class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high)  {

        string universal = "123456789";
        string l1 = to_string(low);
        string l2 = to_string(high);

        vector<int>result;

        int size_l1 = l1.length();
        int size_l2 = l2.length(); 

        for(int i = size_l1;i <= size_l2;i++) {

            for(int j = 0;j <= 9-i;j++) {

                string ans = universal.substr(j,i);
                int number = stoi(ans);

                if(number >= low && number <= high) {
                    result.push_back(number);
                }
            }
        }

        return result;

        //TC : O(1) 
        //SC : O(1).There are only 36 Sequential digits from 10 to 1e9.
        
    }
};