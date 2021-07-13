#include <vector>
#include <string>
using namespace std;

class Trie {
private:
    vector<Trie*> children;
    string word;

public:
    /** Initialize your data structure here. */
    Trie() : children(26, nullptr), word("") {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(char c: word) {
            int index = c-'a';
            if(!root->children[index])
                root->children[index] = new Trie();
            root = root->children[index];
        }
        root->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(char c: word) {
            int index = c-'a';
            if(!root->children[index])
                return false;
            else root=root->children[index];
        }
        return root->word==word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char c: prefix) {
            int index = c-'a';
            if(!root->children[index])
                return false;
            else root=root->children[index];
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

int main() {}