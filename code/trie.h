#ifndef TRIE_H__
#define TRIE_H__

#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct trie_node {
    bool is_word;
    int count = 0;
    char data;
    map<char,trie_node*> children;
};

class Trie {
private:
trie_node* root;

public:
    //contructor and destructor
    Trie();
    ~Trie();

    trie_node* get_root() const{
        return root;
    }
    void clear(trie_node* node);

    void add_word(string word);


    bool lookup(string word);

    int frequency(string word);

    vector<string> auto_complete(string prefix);

    void DFS(trie_node* node,string prefix, vector<string>& complete_words );

    trie_node* find_character(char c);

    void display(trie_node* node, int level, string prefix);
    void display_children(trie_node* node, int level, bool last);
    void print_separator(int level, bool print_bar);
    void print_node(int level, trie_node* node);




};


#endif // TRIE_H__