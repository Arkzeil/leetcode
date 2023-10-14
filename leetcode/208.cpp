class Trie { // save memory but slow, using tree would be much faster
public:
    unordered_map<string, bool> store;
    Trie() {
        store.clear();
    }
    
    void insert(string word) {
        store[word] = true;
    }
    
    bool search(string word) {
        if(store.count(word))
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto i = store.begin(); i != store.end(); i++){
            auto res = mismatch(prefix.begin(), prefix.end(), (*i).first.begin());
            if(res.first == prefix.end())
                return true;
        }
        return false;
    }

private:
    /*class Tree{
        public:
            char letter;
            Tree *left[26];

            Tree(){}
            Tree(char input):letter(input){

            }
    }*/
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
