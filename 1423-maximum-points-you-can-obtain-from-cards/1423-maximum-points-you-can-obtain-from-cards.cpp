class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = INT_MIN;
        
        int totalPoints = 0;
        
        for(auto p : cardPoints) totalPoints += p;
        
        int windowSum = 0;
        for(int i = 0; i < cardPoints.size() - k; i++) windowSum += cardPoints[i];
        
        int i = 0, j = cardPoints.size() - k - 1;
        
        score = max(score, totalPoints - windowSum);
        j++;
        while(j < cardPoints.size()) {
            windowSum += (cardPoints[j++] - cardPoints[i++]);  
            score = max(score, totalPoints - windowSum);
        }
        return score;
    }
};