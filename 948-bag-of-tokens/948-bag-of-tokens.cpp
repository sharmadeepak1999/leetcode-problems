class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int score = 0;
        
        int i = 0, j = tokens.size() - 1;
        
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
            } else {
                if(i != j && score >= 1 && power + tokens[j] >= tokens[i]) {
                    power += tokens[j];
                    score--;
                    j--;
                } else break;
            }
        }
        return score;
    }
};