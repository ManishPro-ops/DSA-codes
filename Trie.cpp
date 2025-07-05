#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26]; // Assuming only lowercase English letters
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    void insert(string& key) {
    TrieNode* crawl = this; // Start at the current node (root)
    for (char c : key) {
        int index = c - 'a'; // Map character to index
        if (!crawl->children[index]) {
            crawl->children[index] = new TrieNode(); // Create a new TrieNode if not exists
        }
        crawl = crawl->children[index]; // Move to the next node
    }
    crawl->isEndOfWord = true; // Mark the end of the word
}


    bool search(string& key) {
        TrieNode* crawl = this;
        for (char c : key) {
            int index = c - 'a';
            if (!crawl->children[index]) {
                return false;
            }
            crawl = crawl->children[index];
        }
        return crawl->isEndOfWord;
    }

    bool isprefix(string& key) {
        TrieNode* crawl = this;
        for (char c : key) {
            int index = c - 'a';
            if (!crawl->children[index]) {
                return false; // Prefix not found
            }
            crawl = crawl->children[index];
        }
        return true; // All characters in the prefix are found
    }
};

int main() {
    TrieNode* root = new TrieNode();

    string word1 = "manish";
    string word2 = "man";
    string word3 = "mango";

    root->insert(word1);
    root->insert(word2);
    root->insert(word3);

    cout << (root->search(word1) ? "manish found\n" : "manish not found\n"); // Expected: found
    cout << (root->search(word2) ? "man found\n" : "man not found\n");       // Expected: found
    cout << (root->search(word3) ? "mango found\n" : "mango not found\n");   // Expected: found

    string prefix2="maal";
    cout << (root->isprefix(word1) ? "manish exists\n" : "Prefix man doesn't exist\n"); // Expected: exists
    cout << (root->isprefix(prefix2) ? "maal doesn't exists\n" : "maal doesn't exists\n"); // Expected: exists

    return 0;
}
