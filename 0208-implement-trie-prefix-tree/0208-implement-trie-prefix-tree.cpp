class TrieNode {
public: 
    bool flag;
    TrieNode* children[26];
    TrieNode() {
        flag = false;
        for(int i=0;i<26;i++) {
            children[i]=nullptr;
        }
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* dummyRoot = root;

        for( char e : word) {
            int idx = e - 'a';
            if (dummyRoot->children[idx]==nullptr) {
                TrieNode* newNode = new TrieNode();
                dummyRoot-> children[idx] = newNode;
                dummyRoot = newNode;
            } else {
                dummyRoot = dummyRoot->children[idx];
            }
        }

        dummyRoot -> flag = true;
    }
    
    bool search(string word) {
        TrieNode* dummyRoot = root;

        for(char e : word) {
            int idx = e - 'a';

            if(dummyRoot->children[idx]!=nullptr) {
                dummyRoot = dummyRoot->children[idx]; 
            } else {
                return false;
            }
        }

        return dummyRoot->flag;
    }
    
    bool startsWith(string prefix) {
        TrieNode* dummyRoot = root;

        for(char e : prefix) {
            int idx = e - 'a';

            if(dummyRoot->children[idx]!=nullptr) {
                dummyRoot = dummyRoot->children[idx]; 
            } else {
                return false;
            }
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