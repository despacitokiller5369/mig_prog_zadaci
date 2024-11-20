#pragma once

#include <unordered_map>
#include <string>

using namespace std;

class PatriciaTrieNode {
public:
    string prefix;
    unordered_map<char, PatriciaTrieNode*> children;
    bool isWord;

    PatriciaTrieNode(const string& prefix = "");
    ~PatriciaTrieNode();
};

class PatriciaTrie {
    PatriciaTrieNode* root;

    void preorder(PatriciaTrieNode* node, const string& prefix, vector<string>& result);
    void clear(PatriciaTrieNode* node);
public:
    PatriciaTrie();
    ~PatriciaTrie();

    void insert(const string& word);
    bool search(const string& word);
    bool startsWith(const string& prefix);
    void print();
};