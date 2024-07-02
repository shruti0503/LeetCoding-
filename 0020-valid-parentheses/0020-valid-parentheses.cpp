class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        if(size==1 || s[0]==')' ||s[0]==']' ||s[0]=='}'|| s[size-1]=='(' ||s[size-1]=='['||s[size-1]=='{')return false;
        stack<char>st;
        for(int i = 0 ; i<size; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')st.push(s[i]);
            else{
                if(st.empty())return false;
                if(s[i]==')'){
                    if(st.top()!='(')return false;
                    else st.pop();
                }
                else if(s[i]==']'){
                    if(st.top()!='[')return false;
                    else st.pop();
                }
                
                else if(s[i]=='}'){
                    if(st.top()!='{')return false;
                    else st.pop();
                }
            }
        }
        if(!st.empty())return false;
        return true;
    }
};