class Solution {
public:
    string reverseWords(string s) {

        string temp;
        int n = s.length();

        //Trimmed out Middle spaces.

        if(s[0] == ' ' && s[1] != ' ') {
            temp.push_back(s[0]);
        }
        else if(s[0]!=' ') {
            temp.push_back(s[0]);
        }

        for(int i = 1; i < n;i++) {
            if(s[i] == ' ' && s[i-1] == ' ') {
                continue;
            }
            else {
                temp.push_back(s[i]);
            }
        }

        int n1 = temp.length();
        int i = 0;

        //Trimmed out leading spaces or trailing spaces.

        while(temp[i] == ' ') {
            i++;
        }
        int j = n1-1;

        while(temp[j] == ' ') {
            j--;
        }

        string temp1 = temp.substr(i,j-i+1);

        vector<string>temp2;

        i = 0;
        j = 0;

        while(i < temp1.length() &&  j < temp1.length()) {
            string temp3 = "";
            while(j < temp1.length() && temp1[j] !=' ') {
                temp3.push_back(temp1[j]);
                j++;
            }
            temp2.push_back(temp3);

            if(j < temp1.length() && temp1[j] == ' ')
            temp2.push_back(" ");
        
            j++;
        }   

        reverse(temp2.begin(),temp2.end());

        string ans;
        for(int i =0;i< temp2.size();i++) {
            string temp5 = temp2[i];
            ans += temp5;
        }

        return ans;

        //TC : O(n^2)
        //SC : O(n^2)

        
    }
};