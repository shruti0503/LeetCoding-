class Solution {
public:
    int myAtoi(string s) {
         // Base Case: String is empty
        if(s.length() == 0){
            return 0;
        }
        
        // Removing the leading whitespaces
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        
        // Removing the whitespaces by creating a substring
        // And updating that as the given string;
        s = s.substr(i);
        
        // Checking the sign of the given number
        // In the end we will multiply this with the answer
        int flag = 1;
        if(s[0] == '-'){
            flag = -1;
        }
        
        /* 
            If the first character is a sign, then we iterate from 
            the next index and else we continue with the 0 index.
        */
        
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        /*
            Initiating the answer variable as long ans
            Since if in case the answer exceeds the integer limit
            The loop below would break and thereafter we couldn't
            Return our variable as integer, possibly giving errors
        */
        
        long ans = 0;
        
        /*
            Running the loop below
            Here, we keep 2 conditions:
                -> i is less than the length of string
                -> the character i is pointing to lies between 0 to 9
            
            This satisfies the confition where we might face another 
            Character while getting numbers or even another whitespace
            
            After that, we check whether we have exceeded the integer limit
            Or not. This is done by the following:
                -> If the answer is negative (Checked from the flag),
                Then we check whether the ans * flag is smaller than 
                INT_MIN
                -> If the answer is positive, we simply check whether
                The ans is greater than INT_MAX
            In both the cases, we return the maximum number respectively
        */
        
        for(; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++){
            ans = ((ans * 10) + (s[i] - '0'));
            
            if(flag == -1){
                if(ans * -1 < INT_MIN){
                    return INT_MIN;
                }
            } else {
                if(ans > INT_MAX){
                    return INT_MAX;
                }
            }
        }
        
        // Finally, we typecast the integer and return it with its corrosponding
        // Sign
        
        return (int)(ans * flag);
        
        
    }
};