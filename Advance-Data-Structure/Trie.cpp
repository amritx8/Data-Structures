#include<bits/stdc++.h>
using namespace std;

struct Trie {
    
    unordered_map<char, Trie*> children;
    bool isword;

    Trie() {

        isword = false;
    }
};

void insert(Trie *root, string s) {

    for(int i = 0; i < s.size(); i++) {

        if(root->children[s[i]] == NULL) {

            root->children[s[i]] = new Trie();
        }

        root = root->children[s[i]];
    }

    root->isword = true;
}

bool search(Trie *root, string s) {

    for(int i = 0; i < s.size(); i++) {

        if(root->children[s[i]] == NULL) {

            return false;
        }

        root = root->children[s[i]];
    }
    
    return root->isword;
}


int main() {

    Trie *root = new Trie();

    return 0;
}