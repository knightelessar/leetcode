// Look at Java solution side by side and translate into C++
// Time spent: 1h 10m
class TrieNode
{
    static const int R = 26;
    TrieNode *links[R];
    bool isWordEnd;

public:
    TrieNode() : isWordEnd(false)
    {
        for (size_t i{0}; i < R; ++i)
        {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        isWordEnd = true;
    }

    bool isEnd()
    {
        return isWordEnd;
    }

    ~TrieNode()
    {
        // https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
        // see Lin Jian's answer
        for (size_t i{0}; i < R; ++i)
        {
            if (links[i])
            {
                delete (links[i]);
            }
        }
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode;
    }

    ~Trie()
    {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (size_t i{0}; i < word.size(); ++i)
        {
            char currentChar = word[i];
            if (!node->containsKey(currentChar))
            {
                node->put(currentChar, new TrieNode);
            }
            node = node->get(currentChar);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = searchPrefix(word);
        return node && node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *node = searchPrefix(prefix);
        return node;
    }

private:
    TrieNode *searchPrefix(string word)
    {
        TrieNode *node = root;
        for (size_t i{0}; i < word.size(); ++i)
        {
            char curLetter = word[i];
            if (node->containsKey(curLetter))
            {
                node = node->get(curLetter);
            }
            else
            {
                return nullptr;
            }
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
