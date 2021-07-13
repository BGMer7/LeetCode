#include <vector>
#include <string>
using namespace std;

class Trie {
    
public:
    vector<Trie*> children;
    string word;

    Trie(): children(26), word("") {}
    ~Trie() {
        for(Trie* t: children) 
            delete t;
    }
};

class WordDictionary {
private:
    Trie *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* cur = root;
        for(char c: word) {
            int index = c-'a';
            if(!cur->children[index])
                cur->children[index] = new Trie();
            cur = cur->children[index];
        }
        cur->word = word;
    }
    
    bool match(string word, int index, Trie* root) {
        if(index==word.size()) return root->word!="";
        for(int i(index); i<word.size(); ++i) {
            if(word[i]=='.') {
                for(auto child: root->children) {
                    if(child)  {
                        root = child;
                        if(match(word, i+1, root)) return true;
                    }
                }
                return false;
            }
            else {
                if(root->children[word[i]-'a']==nullptr)
                    return false;
                root = root->children[word[i]-'a'];
            }
        }
        return root->word!="";
    } 

    bool search(string word) {
        Trie *cur = root;
        return match(word, 0, cur);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {}