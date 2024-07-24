// Definition for the TrieNode structure
struct TrieNode {
    TrieNode* children[26];  // Array of pointers to child nodes
    string word;  // To store the word at the end of a word path
    bool flag = false;  // Indicates if the node represents the end of a word
    
    // Constructor to initialize the TrieNode
    TrieNode() : word("") {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    // Check if there is a child node corresponding to the character 'ch'
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    // Get the child node corresponding to the character 'ch'
    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    // Put a new child node corresponding to the character 'ch'
    void put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }

    // Mark the node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the node is the end of a word
    bool isEnd() {
        return flag;
    }
};

// Definition for the Trie class
class Trie {
public:
    // Constructor to initialize the Trie with a root node
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->word = word;
        node->setEnd();
    }

    // Get the root node of the Trie
    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;  // Root node of the Trie
};

// Depth-First Search (DFS) function to find words on the board
void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, unordered_set<string>& result_set) {
    char ch = board[i][j];
    
    // Return if the cell is already visited or the character is not in the Trie
    if(ch == '#' || !node->containsKey(ch)) return;
    
    node = node->get(ch);
    
    // If the node is the end of a word, add the word to the result set
    if(node->isEnd()) {
        result_set.insert(node->word);
    }

    board[i][j] = '#';  // Mark the cell as visited
    
    // Direction vectors for moving up, down, left, and right
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for(auto dir : dirs) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        
        // Check if the new position is within the board boundaries
        if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
            dfs(board, ni, nj, node, result_set);
        }
    }
    board[i][j] = ch;  // Unmark the cell
}

// Definition for the Solution class
class Solution {
public:
    // Function to find all words from the dictionary in the board
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        
        // Insert all words into the Trie
        for(string word : words) {
            trie.insert(word);
        }
        
        unordered_set<string> result_set;  // To store the unique words found on the board
        TrieNode* root = trie.getRoot();  // Get the root node of the Trie

        // Perform DFS for each cell in the board
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result_set);
            }
        }

        // Convert the result set to a vector and return
        return vector<string>(result_set.begin(), result_set.end());
    }
};