class Solution {
public:

    string reverseWords(string s) {

        string temp;
        int n = s.length();

        //1.Trimmed out Middle Multiple spaces.

        if(s[0] == ' ') {
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

        //2.Trimmed out leading spaces or trailing spaces.

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

        while( j < temp1.length()) {

            string temp3 = "";
            
            while(j < temp1.length() && temp1[j] !=' ') {
                temp3.push_back(temp1[j]);//a  "good"
                j++;
            }

            temp2.push_back(temp3);//"a" 

            if(j < temp1.length() && temp1[j] == ' ')
            temp2.push_back(" ");//string of spaces = " "
        
            j++;
        } //O(n)  

        reverse(temp2.begin(),temp2.end());//O(n)

        string ans;

        for(int i =0;i< temp2.size();i++) {
            string temp5 = temp2[i];
            ans += temp5;//Concatenate all the strings at the end.
        }

        return ans;

        //TC : O(n)
        //SC : O(n)

        
    }
};