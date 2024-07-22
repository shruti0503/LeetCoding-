struct Node{
    Node* links[26];
    bool flag=false;

    // check if this node has the link to the spciifc charcter
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }

    //Insert a new node with the carcter
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    // get the node with speiifc letter from the Trie
    Node* get(char ch){
        return links[ch-'a'];
    }

    // set the current node as the end of the word
    void setEnd(){
        flag=true;
    }

    // check if the current node marks the end of a word
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
   Node* root;
    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        // start at the root node 
        // for each character has a child node corresponding t that cgharcater
        // if not, create a new node and link it as a child of the current node
        // move to the chilkd node corresponfg chaccter

        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();  
    }
    
    bool search(string word) {
        // search dfor a word
        // 1start at the root node
        //2 FOR EACH VHRACTER IN THE WORD-> check if the current node has a child. node corresponding to the charcter
        // if not -> the word is not the trie
        // move to the child node corresponding to the character 

        Node * node= root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd(); // check if the last node marks the end of the wrd

    }
    // check if trie contains prefix
    // 1.start at the root node
    // 2. for each cgaracter in the prefix -> check ifthe current node has a child node
    // correxpong to the chrcter 
    // 3-> if not there is no word  with the given prefix -> move to the child node corrresping to the carctaer
    bool startsWith(string prefix) {

        Node* node= root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */