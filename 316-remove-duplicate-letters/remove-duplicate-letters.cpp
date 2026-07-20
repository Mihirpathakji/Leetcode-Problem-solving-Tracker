class Solution {
public:

    string removeDuplicateLetters(string s) {

        int n = s.length();

        vector<int>last_indices(26,-1);
        vector<int>my_ans(26,-1);
     
        for(int i = 0;i < n;i++) {
            last_indices[s[i]-'a'] = i;
        }

        string ans;

        for(int i = 0;i < n;i++) {

            if(ans.empty()) { 
                ans.push_back(s[i]);// c 
                my_ans[s[i] -'a'] = i;// 3        
            }

            else if(ans.back()  <= s[i] && my_ans[s[i]-'a']==-1) {
                ans.push_back(s[i]);//ac acd 
                my_ans[s[i]-'a'] = i;
            }
            else {
                while(!ans.empty() && ans.back() > s[i] && my_ans[s[i] -'a']==-1 ) { 

                    if(last_indices[ans.back()-'a'] > i) {
                        my_ans[ans.back()-'a'] = -1;//-1    
                        ans.pop_back();//
                    }
                    else {
                        ans.push_back(s[i]);
                        my_ans[s[i]-'a'] = i; 
                    }
                }

                if(my_ans[s[i] -'a'] == -1) {
                    ans.push_back(s[i]);//b // acdb.
                    my_ans[s[i]-'a'] = i;//1 // 2 
                }

            }
        
        }
        
        return ans;

        //TC : O(n)
        //SC : O(1)
        
    }
};