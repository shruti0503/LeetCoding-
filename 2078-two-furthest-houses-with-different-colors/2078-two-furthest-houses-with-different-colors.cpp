class Solution {
public:
//brutte force for each number check whether any nuberr is diff cur currennt and and calculate the max distance
   int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(colors[i] != colors[0])
            ans = max(ans, i);
        
        if(colors[i] != colors[n - 1])
            ans = max(ans, n - 1 - i);
    }

    return ans;
}
};