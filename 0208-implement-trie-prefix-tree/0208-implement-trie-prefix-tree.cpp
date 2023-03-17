struct TrieNode{
    bool isEnd;
    array<TrieNode*, 26> links;
    TrieNode(){
        isEnd=0;
        fill(links.begin(), links.end(), (TrieNode*)0);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* Node=root;
        for(char c: word){
            int i=c-'a';
            if(Node->links[i]==NULL)
                Node->links[i]=new TrieNode();
            Node=Node->links[i];
        }
        Node->isEnd=1;
    }
    
    bool search(string word) {
      TrieNode* Node = root;
        for(char c : word){
            int i = c - 'a';
            if(Node->links[i]==NULL) return 0;
            Node = Node->links[i];
        }
        return Node->isEnd;  
    }
    
    bool startsWith(string prefix) {
        TrieNode* Node = root;
        for(char c : prefix){
            int i = c - 'a';
            if(Node->links[i]==NULL) return 0;
            Node = Node->links[i];
        }
        return 1;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */