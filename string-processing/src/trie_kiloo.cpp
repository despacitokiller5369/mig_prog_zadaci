#include "trie_kiloo.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

TrieNode::TrieNode() : isWord(false) {}

Trie::Trie() : root(new TrieNode()) {}

Trie::~Trie() {
    clear(root);
}

void Trie::clear(TrieNode* node) {
    if (!node) return;    
    for (auto& child : node->children) {
        clear(child.second);
    }
    delete node;
}

void Trie::insert(const wstring& word) {
    TrieNode* node = root;
    for (wchar_t c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isWord = true;
}

bool Trie::search(const wstring& word) {
    TrieNode* node = root;
    for (wchar_t c : word) {
        if (!node->children.count(c)) return false;
        node = node->children[c];
    }
    return node->isWord;
}

bool Trie::startsWith(const wstring& prefix) {
    TrieNode* node = root;
    for (wchar_t c : prefix) {
        if (!node->children.count(c)) return false;
        node = node->children[c];
    }
    return true;
}

bool Trie::deleteWord(const wstring& word, TrieNode* node, int depth) {
    if (depth == word.size()) {
        if (!node->isWord) return false;
        node->isWord = false;

        return node->children.empty();
    }

    wchar_t c = word[depth];
    if (node->children.count(c) && deleteWord(word, node->children[c], depth + 1)) {
        delete node->children[c];
        node->children.erase(c);

        return !node->isWord && node->children.empty();
    }

    return false;
}

void Trie::preorder(TrieNode* node, wstring& word, vector<wstring>& res) {
    if (!node) return;

    if (node->isWord) {
        res.push_back(word);
    }

    for (auto& [c, child] : node->children) {
        word.push_back(c);
        preorder(child, word, res);
        word.pop_back();
    }
}

void Trie::print() {
    vector<wstring> words;
    wstring word;

    preorder(root, word, words);

    for (wstring w : words) {
        wcout << w << endl;
    }
}

void loadWordsFromTxt(const string& filename, Trie& trie) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Could not open file!" << endl;
        return;
    }

    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    string line;

    while (getline(file, line)) {
        wstring word = converter.from_bytes(line);
        trie.insert(word);
    }
    file.close();
}