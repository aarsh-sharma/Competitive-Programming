class Trie
{
private:
    struct Node
    {
        vector<Node *> next = vector<Node *>(26);
        bool leaf = false;
    };
    Node *root = new Node;

public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto curr = root;
        for (auto ch : word)
        {
            if (!curr->next[ch - 'a'])
            {
                Node *temp = new Node;
                curr->next[ch - 'a'] = temp;
            }
            curr = curr->next[ch - 'a'];
        }
        curr->leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto curr = root;
        for (auto ch : word)
        {
            if (!curr->next[ch - 'a'])
            {
                return false;
            }
            else
            {
                curr = curr->next[ch - 'a'];
            }
        }
        return curr->leaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto curr = root;
        for (auto ch : prefix)
        {
            if (!curr->next[ch - 'a'])
            {
                return false;
            }
            else
            {
                curr = curr->next[ch - 'a'];
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