class Solution {
public:
    string reverseWords(string s) {
         stack<string>stk;
        string temp = "";
        
        //we'll iterate over th string s
        for(auto curr : s)
        {
            //if we have encountered a space 
            //then it implies that we have got a complete word
            //so we'll add it to the stack & will set temp to empty string
            if(curr == ' ')//line14
            {
                if(temp.size() !=0)
                {
                    stk.push(temp);
                    temp = "";
                }
            }
            
            //otherwise we just need to add the curr to temp untill we get a complete word
            else
                temp = temp + curr;
        }
        
        //now we'll need to add the last word of the string to the stack explicitly
        //because there is no space after the last word so won't get into the if statement of line14 & will miss adding last word to stack
        if(temp.size() != 0)
            stk.push(temp);
        
        
        //since we have got all the words in the stack
        //now simply pop out the words and add them to ans
        string ans = "";
        while(stk.size()>1)
        {
            ans = ans + stk.top() + " ";
            stk.pop();
        }
        ans = ans + stk.top();//because we don't want any space after the last word
        return ans;
        
    }
};