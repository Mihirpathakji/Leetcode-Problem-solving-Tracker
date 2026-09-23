class Solution {
public:

    string left_rotate(string original) {
        
        int i = 1;
        int n = original.size();

        string ans;
        while(i < n) {
            ans.push_back(original[i]);
            i++;
        }
        
        ans.push_back(original[0]);

        return ans;
    } 
    
    int minOperations(string s) {

        int n = s.length();

        long long global_min_ops = INT_MAX;//INT_MAX

        string result = s;//abc.
        
        for(int k = 0;k < n;k++) {
            
            string result1 = left_rotate(result);//bca. cab. abc

            int i = 0;
            long long min_ops = 0;
            int j = n-1;

            while(i < j) {
                if(result1[i] == result1[j]) {
                    i++;
                    j--;
                }
                else {

                    int cost1 = 0;///0.
                    
                    if(result1[i]>result1[j]) {
                        cost1 = min(result1[i]-result1[j],'z'-result1[i] + (result1[j]-'a'+1));//1.
                    }//1.

                    else {
                        cost1 = min(result1[j]-result1[i],'z'-result1[j] + (result1[i]-'a'+1));
                    }//2.
                    
                    min_ops += cost1;//1.2.
                    i++;
                    j--;
                }
            }

            if(k!=n-1)
            global_min_ops = min( min_ops + ( k + 1) ,global_min_ops);//(k+1) is the cost of the rotation operation.//2.2.

            else 
            global_min_ops = min(min_ops+0,global_min_ops);//2.

            result = result1;//bca cab abc
             
        } 
        
        return global_min_ops;
    
    }
};