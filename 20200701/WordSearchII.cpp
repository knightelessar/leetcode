class TrieNode
{
public:
    unordered_map<char, TrieNode *> *children;
    string word;
    TrieNode() : word(string())
    {
        children = new unordered_map<char, TrieNode *>;
    }

    ~TrieNode()
    {
        delete children;
    }
};

class Solution
{
    vector<vector<char>> _board;
    vector<string> _result;

public:
    Solution() : _board(vector<vector<char>>()), _result(vector<string>())
    {
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // 1. Construct the trie
        TrieNode root;
        for (string &word : words)
        {
            TrieNode *node = &root;

            for (char letter : word)
            {
                if (node->children->find(letter) != node->children->end())
                {

                    node = node->children->at(letter);
                }
                else
                {
                    TrieNode *newNode = new TrieNode();
                    node->children->insert({letter, newNode});
                    node = newNode;
                }
            }
            node->word = word;
        }

        this->_board = board;
        // 2. Backtrack starting from each cell
        for (size_t row{0}; row < board.size(); ++row)
        {
            for (size_t col{0}; col < board[0].size(); ++col)
            {
                if (root.children->find(board[row][col]) != root.children->end())
                {
                    backtrack(row, col, root);
                }
            }
        }
        return this->_result;
    }

    void backtrack(size_t row, size_t col, TrieNode &parent)
    {
        char letter = this->_board[row][col];
        TrieNode &currNode = *(parent.children->at(letter));

        // if the candidate is a match
        if (!currNode.word.empty())
        {
            this->_result.push_back(currNode.word);
            currNode.word = string();
        }

        // if next candidate is good, mark the current node so that
        // next candidate does not revisit current node.
        this->_board[row][col] = '#';

        // try or backtrack up, right, down, left neighbours
        int rowOffset[] = {-1, 0, 1, 0};
        int colOffset[] = {0, 1, 0, -1};
        for (size_t i{0}; i < 4; ++i)
        {
            int newRow = row + rowOffset[i];
            int newCol = col + colOffset[i];
            if (newRow < 0 || newRow >= this->_board.size() || newCol < 0 || newCol >= this->_board[0].size())
            {
                continue;
            }
            char newLetter = this->_board[newRow][newCol];
            if (currNode.children->find(newLetter) != currNode.children->end())
            {
                backtrack(newRow, newCol, currNode);
            }
        }

        // after backtracking this level, clear up the side effects
        this->_board[row][col] = letter;

        // optimization: remove empty leaf nodes
        if (currNode.children->empty())
        {
            currNode.children->erase(letter);
        }
        return;
    }
};
