class WordDictionary {
private:
    struct TrieNode {
        vector<TrieNode *> next = vector<TrieNode *>(26);
        bool leaf = false;
    };
    TrieNode *root = new TrieNode;
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto curr = root;
        for (auto ch : word) {
            if (!curr->next[ch-'a']) {
                curr->next[ch-'a'] = new TrieNode;
            }
            curr = curr->next[ch-'a'];
        }
        curr->leaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool check(string word, TrieNode *root) {
        auto curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!root) return false;
            if (word[i] == '.') {
                string ss = word.substr(i+1);
                for (int j = 0; j < 26; j++) {
                    if (check(ss, curr->next[j])) return true;
                }
                return false;
            }
            if (!curr->next[word[i]-'a']) {
                return false;
            }
            curr = curr->next[word[i]-'a'];
        }
        return root and curr->leaf;
    }
    
    bool search(string word) {
        return check(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */