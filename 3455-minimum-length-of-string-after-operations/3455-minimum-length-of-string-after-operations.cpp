class Solution {
public:
    int minimumLength(string s) {
        // yha par notice karo ki ek char ki teen copy honi zaruri h remove krne k liye left aur right
 // so , count of a character/3
 // even will go down to 1
 // odd will go down to 2
 unordered_map<char,int>mpp;
 for(auto it:s){
    mpp[it]++;
 }
 int len=0;
 for(auto it:mpp){
    if(it.second%2!=0) len++;
    else if(it.second%2==0) len+=2;
 }
 return len;

    }
};