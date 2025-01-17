class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int maxarea=INT_MIN;

        while(i<j){
            int h=min(height[i],height[j]);
             int area=(j-i)*h;
             maxarea=max(maxarea, area);
             if(h==height[i]){
                i++;
             }
             else{
                j--;
             }
            
        }
        return maxarea;
        
        
    }
};