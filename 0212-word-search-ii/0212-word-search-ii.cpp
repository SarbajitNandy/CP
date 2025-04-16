class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;

    TrieNode() : word("") {}
};

class Solution {
private:
    vector<vector<char>> _board;
    vector<string> _result;

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char letter : word) {
                if (node->children.find(letter) != node->children.end()) {
                    node = node->children[letter];
                } else {
                    TrieNode* newNode = new TrieNode();
                    node->children[letter] = newNode;
                    node = newNode;
                }
            }
            node->word = word;
        }

        _board = board;
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (root->children.find(board[row][col]) !=
                    root->children.end()) {
                    backtracking(row, col, root);
                }
            }
        }

        return _result;
    }

private:
    void backtracking(int row, int col, TrieNode* parent) {
        char letter = _board[row][col];
        TrieNode* currNode = parent->children[letter];

        if (currNode->word != "") {
            _result.push_back(currNode->word);
            currNode->word = "";  
        }

        _board[row][col] = '#';

        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int newRow = row + rowOffset[i];
            int newCol = col + colOffset[i];
            if (newRow < 0 || newRow >= _board.size() || newCol < 0 ||
                newCol >= _board[0].size()) {
                continue;
            }
            if (currNode->children.find(_board[newRow][newCol]) !=
                currNode->children.end()) {
                backtracking(newRow, newCol, currNode);
            }
        }

        _board[row][col] = letter;

        if (currNode->children.empty()) {
            parent->children.erase(letter);
        }
    }
};