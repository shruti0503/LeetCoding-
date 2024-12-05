class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0, currentSum = 0;
        int maxScore = 0;

        // Calculate the initial sum of the first `k` cards
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxScore = leftSum; // Start with the maximum as the initial left sum

        // Sliding window: Move cards from left to right
        int rightIndex = n - 1;
        for (int j = k - 1; j >= 0; j--) {
            leftSum -= cardPoints[j];       // Remove the last card from the left
            rightSum += cardPoints[rightIndex]; // Add a card from the right
            currentSum = leftSum + rightSum; // Calculate the new sum
            maxScore = max(maxScore, currentSum); // Update the maximum score
            rightIndex--;                  // Move to the next card on the right
        }

        return maxScore;
    }
};