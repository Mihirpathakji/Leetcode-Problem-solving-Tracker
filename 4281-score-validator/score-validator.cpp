class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        vector<int>ans;

        //events[i] == "0" -> String is an array of characters.i.e iterating on that string "0" will give us only a character.

        int counter = 0;
        int score = 0;    

        for(int i = 0 ; i  < events.size(); i++)
        {   
            if(counter == 10)
            {
                break;
            }
            if(events[i]!= "WD" && events[i]!="NB" && events[i]!="W")
            {
                char ch;
                for(auto it : events[i])
                {
                    //it -> characters 
                    ch = it;//characters
                }

                score += ch-'0';
            }
            else if(events[i] == "W")
            {
                counter++;
            }
            else if(events[i] == "WD" || events[i] == "NB")
            {
                score++;
            }
        }

        ans.push_back(score); 
        ans.push_back(counter);

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};