class Solution {
public:
// The brute force approach for this problem involves calculating the area formed by every pair of vertical lines and keeping track of the maximum area found so far. Here are the steps for the brute force approach

// Initialize a variable max_area to 0, which will keep track of the maximum area found so far.

// Loop through each pair of vertical lines. We can do this by having two nested loops, where the outer loop iterates over the first vertical line and the inner loop iterates over the second vertical line.

// Calculate the area formed by the current pair of vertical lines using the formula:

// area = min(height[i], height[j]) * (j - i)

// where i and j are the indices of the two vertical lines and height[i] and height[j] are their respective heights.

// If the area calculated in step 3 is greater than max_area, update max_area to the new area.
// Return max_area as the result.

    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int area;
        int maxarea=0;
// Initialize two variables area and maxarea to 0. area will be used to calculate the area formed between the current two vertical lines and maxarea will keep track of the maximum area found so far.
        while(s<e){
// Calculate the area formed between the two vertical lines pointed by s and e using the formula: min(height[s], height[e]) * (e - s). This formula finds the area between the two vertical lines, where the height of the container will be limited by the shorter of the two lines and the width of the container will be equal to the distance between the two lines.
// If the area calculated in step 4 is greater than maxarea, update maxarea with the new area.
            area=(min(height[s],height[e])*(e-s));
            if(area>maxarea){
                maxarea=area;
            }
            if(min(height[s],height[e])==height[s]){
                s++;
            }
            else{
                e--;
            }
// If height[s] is shorter than height[e], increment s by 1, otherwise decrement e by 1. This is done to ensure that we move the pointer pointing to the shorter line inward, as moving the pointer pointing to the longer line will only decrease the area formed.

// Return maxarea as the result.
            
        }
        return maxarea;
    }
};