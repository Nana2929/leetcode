// 211. Design Add and Search Words Data Structure
// Description: https://leetcode.com/problems/design-add-and-search-words-data-structure/
#include <stdio.h>
#include<iostream>
#include<vector>
#include <string.h> // memset
using namespace std;
class TrieNode
{
public:
    bool is_word;
    TrieNode *children[26];
    TrieNode()
    {
        is_word = false;
        memset(children, 0, sizeof(children));
    }
}; 

class WordDictionary {
public:
    WordDictionary() {
        // TrieNode* node = new root  Q. 在這邊寫呢？
    }
    void addWord(string word) {
        TrieNode* node = root;
        for (auto c: word){
            if (!node->children[c - 'a']){
                // pointer to a newed trienode
                node-> children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node -> is_word = true;
    }

    bool search(string word) {
        return search(word, 0, root);
    }
private:
    TrieNode* root = new TrieNode();
    bool search(string &word, int index, TrieNode* node){
        if (!node){return 0;}
        if (index == word.size()){return node->is_word;};
        char c = word[index];
        if (c != '.'){
            if (!node->children[c-'a']){
                return false;
            }
            return search(word, index+1, node->children[c-'a']);
        }
        for (auto v:node->children){
            if (search(word, index+1, v)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
