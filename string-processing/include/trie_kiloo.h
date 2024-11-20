#pragma once

#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<wchar_t, TrieNode*> children;
    bool isWord;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
    
    void preorder(TrieNode* node, wstring& word, vector<wstring>& res);
    void clear(TrieNode* node);
public:
    Trie();
    ~Trie();

    void insert(const wstring& word);
    bool search(const wstring& word);
    bool startsWith(const wstring& prefix);
    bool deleteWord(const wstring& word, TrieNode* node, int depth);
    void print();

};

void loadWordsFromTxt(const string& filename, Trie& trie);