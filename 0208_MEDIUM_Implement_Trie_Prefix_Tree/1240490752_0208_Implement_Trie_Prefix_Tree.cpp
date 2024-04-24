class TrieNode
{
    public:
    vector <TrieNode*> dict;
    bool isEnd;
    TrieNode()
    {
        isEnd= false;
        dict.resize(26,NULL);
    }
};
class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        //iterate over the word
        for(int i=0;i<word.length();i++)
        {
            //if no node exist for that letter, create a new node
            if(node->dict[word[i] -'a'] == NULL)
            {
                node->dict[word[i]-'a'] = new TrieNode();
            }
            node = node->dict[word[i]-'a'];
        }
        node->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->dict[word[i]-'a']== NULL)
            {
                return false;
            }
            node = node->dict[word[i]-'a'];
        }
        return node->isEnd;
        
    }
    
    bool startsWith(string prefix) {
                TrieNode* node = root;
        for(int i=0;i<prefix.length();i++){
            if(node->dict[prefix[i]-'a']==NULL)
                return false;
            node = node->dict[prefix[i]-'a'];
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