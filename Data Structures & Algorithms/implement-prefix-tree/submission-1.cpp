#include <string>
#include <unordered_map>

using namespace std;

class PrefixTree {
public:
    struct TreeNode {
        char letter; 
        unordered_map<char, TreeNode*> m;
        bool isEnd = false; 

        TreeNode(char ch = '\0') : letter(ch), isEnd(false) {}
    };

    TreeNode* root; 

    PrefixTree() {
        root = new TreeNode(); 
    }
    
    void insert(string word) {
        TreeNode* curr = root; 
        
        for (char c : word) {
            if (curr->m.find(c) == curr->m.end()) {
                curr->m[c] = new TreeNode(c);
            }
            curr = curr->m[c];
        }
        
        curr->isEnd = true; 
    }
    
    bool search(string word) {
        TreeNode* curr = root;
        
        for (char c : word) {
            if (curr->m.find(c) == curr->m.end()) {
                return false;
            }
            curr = curr->m[c];
        }
        
        return curr->isEnd; 
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = root;
        
        for (char c : prefix) {
            if (curr->m.find(c) == curr->m.end()) {
                return false; 
            }
            curr = curr->m[c];
        }
        
        return true; 
    }
};