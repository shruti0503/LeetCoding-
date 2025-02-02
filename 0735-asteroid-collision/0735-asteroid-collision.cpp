

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;  
        for (int i = 0; i < ast.size(); i++) {
            bool destroyed = false; 
            
            while (!st.empty() && ast[i] < 0 && st.top() > 0) {
                if (st.top() < abs(ast[i])) {
                    st.pop();
                    continue; 
                } else if (st.top() == abs(ast[i])) {
                    st.pop();
                }
                destroyed = true;  
                break;
            }
            if (!destroyed) {
                st.push(ast[i]);
            }
        }
        
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};