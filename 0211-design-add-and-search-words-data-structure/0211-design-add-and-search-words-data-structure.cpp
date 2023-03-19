struct Node {
private:
    Node* links[26];
    bool flag = false;

public:
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void insert(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {

        Node* node = root;

        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->insert(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool searchDFS(Node* node, string word, int ind) {
        if (ind == word.size()) {
            if (node->isEnd()) return true;
            else return false;
        }

        if (word[ind] != '.') {
            if (!node->containsKey(word[ind])) return false;
            else {
                return searchDFS(node->get(word[ind]), word, ind + 1);
            }
        }
        else {
            for (char i='a'; i<='z'; i++) {
                if (node->containsKey(i)) {
                    bool temp = searchDFS(node->get(i), word, ind + 1);
                    if (temp) return true;
                }
            }

            return false;
        }
    }
    
    bool search(string word) {
        Node* node = root;
        return searchDFS(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */