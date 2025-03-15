class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>>pq;
        pq.push({beginWord,1});
        st.erase(beginWord);

        while(!pq.empty()){
            auto node=pq.front();
            pq.pop();
            string word=node.first;
            int steps=node.second;

            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char orgChar=word[i];// current word uthao
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        pq.push({word, steps+1});
                    }
                }
                word[i]=orgChar;
            }
            
        }
        return 0;
        
    }
};