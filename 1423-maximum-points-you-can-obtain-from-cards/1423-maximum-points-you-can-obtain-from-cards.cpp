class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        int i = 0, j = cardPoints.size() - k;
        for(int l = j; l < cardPoints.size(); l++) total += cardPoints[l];
        int score = total;
        while(j < cardPoints.size()) {
            total += (cardPoints[i++] - cardPoints[j++]);  
            score = max(score, total);
        }
        return score;
    }
};