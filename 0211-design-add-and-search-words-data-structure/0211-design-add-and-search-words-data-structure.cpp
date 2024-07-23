#include <vector>
#include <string>

using namespace std;

struct Node {
    Node* links[26];
    bool isEnd; // Changed from flag to isEnd for clarity

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndNode() {
        return isEnd;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }

private:
    bool searchHelper(Node* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEndNode();
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->containsKey('a' + i) && searchHelper(node->get('a' + i), word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->containsKey(ch)) {
                return false;
            }
            return searchHelper(node->get(ch), word, index + 1);
        }
    }
};