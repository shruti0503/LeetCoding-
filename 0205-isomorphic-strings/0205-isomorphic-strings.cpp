class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<n1; i++){
            if(!m1[s[i]] && !m2[t[i]]){
                m1[s[i]]=t[i];
                
                m2[t[i]]=s[i];

            }
            else if(m1[s[i]] != t[i]) return false;
            
        }
        return true;
        
    }
};