struct Node{
  Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
     void put(char ch, Node*node){
        links[ch-'a']=node;
     }

     Node* get(char ch){
        return links[ch-'a'];
     }

     void setEnd(){
        flag=true;
     }

     bool isEnd(){
        return flag;
     }
};


class WordDictionary {
public:
Node* root;
    WordDictionary() {
        root= new Node();
        
    }
    
    void addWord(string word) {

        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            node= node->get(word[i]); // move to next word
        }
        node->setEnd();

        
        
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0); // Start the search from the root
        
    };
    private:
    bool searchHelper(Node* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEnd(); // Return true if the end of the word is reached
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->containsKey('a' + i) && searchHelper(node->get('a' + i), word, index + 1)) {
                    return true; // If any child node matches, return true
                }
            }
            return false; // No match found
        } else {
            if (!node->containsKey(ch)) {
                return false; // Character not found in the current path
            }
            return searchHelper(node->get(ch), word, index + 1); // Move to the next character
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */