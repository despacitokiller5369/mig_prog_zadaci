#include "patricia_kiloo.h"

#include <iostream>

using namespace std;

PatriciaTrieNode::PatriciaTrieNode(const string& prefix) : prefix(prefix), isWord(false) {}

PatriciaTrieNode::~PatriciaTrieNode() {
    for (auto& child : children) {
        delete child.second;
    }
}

PatriciaTrie::PatriciaTrie() : root(new PatriciaTrieNode()) {}

PatriciaTrie::~PatriciaTrie() {
    clear(root);
}

void PatriciaTrie::clear(PatriciaTrieNode* node) {
    if (!node) return;
    for (auto& child : node->children) {
        clear(child.second);
    }
    delete node;
}

void PatriciaTrie::insert(const string& word) {
    PatriciaTrieNode* node = root;
    size_t index = 0;

    while (index < word.size()) {
        char c = word[index];

        if (node->children.count(c)) {
            PatriciaTrieNode* child = node->children[c];
            string& prefix = child->prefix;

            size_t i = 0;
            while (i < prefix.size() && index + i < word.size() && prefix[i] == word[index + i]) {
                i++;
            }

            if (i == prefix.size()) {
                node = child;
                index += i;
            } else {
                PatriciaTrieNode* splitNode = new PatriciaTrieNode(prefix.substr(i));
                splitNode->children = move(child->children);
                splitNode->isWord = child->isWord;

                child->prefix = prefix.substr(0, i);
                child->children.clear();
                child->children[splitNode->prefix[0]] = splitNode;
                child->isWord = false;

                if (index + i < word.size()) {
                    PatriciaTrieNode* newNode = new PatriciaTrieNode(word.substr(index + i));
                    newNode->isWord = true;
                    child->children[word[index + i]] = newNode;
                } else {
                    child->isWord = true;
                }
                return;
            }
        } else {
            PatriciaTrieNode* newNode = new PatriciaTrieNode(word.substr(index));
            newNode->isWord = true;
            node->children[c] = newNode;
            return;
        }
    }
    node->isWord = true;
}

bool PatriciaTrie::search(const string& word) {
    PatriciaTrieNode* node = root;
    size_t index = 0;

    while (index < word.size()) {
        char c = word[index];

        if (!node->children.count(c)) {
            return false;
        }

        PatriciaTrieNode* child = node->children[c];
        const string& prefix = child->prefix;

        size_t i = 0;
        while (i < prefix.size() && index + i < word.size() && prefix[i] == word[index + i]) {
            i++;
        }

        if (i < prefix.size()) {
            return false;
        }

        node = child;
        index += i;
    }

    return node->isWord;
}

bool PatriciaTrie::startsWith(const string& prefix) {
    PatriciaTrieNode* node = root;
    size_t index = 0;

    while (index < prefix.size()) {
        char c = prefix[index];

        if (!node->children.count(c)) {
            return false;
        }

        PatriciaTrieNode* child = node->children[c];
        const string& prefix = child->prefix;

        size_t i = 0;
        while (i < prefix.size() && index + i < prefix.size() && prefix[i] == prefix[index + i]) {
            ++i;
        }

        if (i < prefix.size()) {
            return false;
        }

        node = child;
        index += i;
    }

    return true;
}

void PatriciaTrie::preorder(PatriciaTrieNode* node, const string& prefix, vector<string>& result) {
    if (!node) return;

    if (node->isWord) {
        result.push_back(prefix + node->prefix);
    }

    for (auto& [c, child] : node->children) {
        preorder(child, prefix + node->prefix, result);
    }
}

void PatriciaTrie::print() {
    vector<string> words;
    preorder(root, "", words);

    for (const auto& word : words) {
        cout << word << endl;
    }
}