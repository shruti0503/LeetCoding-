class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;  

        vector<int> reachable(n, 0);  
        reachable[0] = 1;  

        int farthest = 0;  

        for (int i = 1; i < n; i++) {
           
            if (i >= minJump && reachable[i - minJump] == 1) {
                farthest = max(farthest, i - minJump);
            }
            if (i >= farthest + minJump && i <= farthest + maxJump && s[i] == '0') {
                reachable[i] = 1; 
            }
        }

        return reachable[n - 1] == 1;  
    }
};
