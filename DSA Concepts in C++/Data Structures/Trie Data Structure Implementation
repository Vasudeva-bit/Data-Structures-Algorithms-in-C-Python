class TrieNode {
    public:
    bool end;
    unordered_map<char, TrieNode*> umap;
    TrieNode(){
        end = false;
    }
};


class Trie {
public:
    TrieNode* root = NULL;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto ch:word) {
            if(curr->umap.find(ch) == curr->umap.end()){
                curr->umap[ch] = new TrieNode();
            }
            curr = curr->umap[ch];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto ch:word){
            if(curr->umap.find(ch) == curr->umap.end())
                return false;
            curr = curr->umap[ch];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto ch:prefix){
            if(curr->umap.find(ch) == curr->umap.end())
                return false;
            curr = curr->umap[ch];
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