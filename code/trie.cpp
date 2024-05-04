#include "trie.h"

Trie::Trie() {
    root = new trie_node();
}
 
Trie::~Trie() {
    clear(root); // Start recursive deletion from the root
}

void Trie::clear(trie_node* node) {
    if (node == nullptr) return;
    for (auto& child : node->children) {
        clear(child.second); // Recursive delete
    }
    delete node; // Delete the current node after its children
}

void Trie::add_word(string word){
    //check input
    if(word.length() == 0){
        throw invalid_argument("Can not add an empty word to the trie");
    }   

    trie_node* node = root;

    for(char c : word){
        //check map to see if child exists for c
        if (node->children.count(c) ==0){
            //create new entry if not
            node->children[c] = new trie_node();
            node->children[c]->data = c;
        }

        //if c is a child, move to next node' 
        node = node->children[c];
        
    }
    //at last character, flag node as end of word
     node->count++;
    node->is_word = true;
    }


bool Trie::lookup(string word){
    trie_node* node = root;

    for(char c:word){
        if (node->children.count(c) ==0){
            return false;
        }
        else{
            node = node->children[c];
        }
    }
    if(node->is_word){
        return true;
    }
    return false;
}


int Trie::frequency(string word){
    trie_node* node = root;

    for(char c:word){
        if (node->children.count(c) ==0){
            return 0;
        }
        else{
            node = node->children[c];
        }
    }
    if(node->is_word){
        return node->count;
}
    return 0;
    
}

vector<string> Trie::auto_complete(string prefix){
    trie_node* node = root;

    for(char c : prefix){
        if(node->children.count(c)==0){
            return {};
        }
        //go to next node
        node = node->children[c];
    }

    vector<string> complete_words;
    if(node!=nullptr){
        DFS(node,prefix,complete_words);
    }
    return complete_words;
    }


void Trie::DFS(trie_node* node, string prefix, vector<string>& complete_words ){
   
    //check if input node is end of word
    if(node->is_word){
        complete_words.push_back(prefix);
    }

    //recursive DFS to find the end of word
    for(auto it = node->children.begin(); it !=node->children.end(); it++){
        //access char and child from map [c,child]  
        char c = it->first;
        trie_node* child = it->second;
        string new_prefix = prefix+c;
        DFS(child, new_prefix, complete_words);
    }
}

trie_node* Trie::find_character(char c){
    trie_node* node_with_c= root;

    if (node_with_c->children.count(c) ==0){
            return nullptr;
        }
    else{
            node_with_c = node_with_c->children[c];
        }
    return node_with_c;
}


void Trie::display(trie_node* node, int level, string prefix) {
    if (!node) return;

    print_node(level, node);
    
    bool last_sibling = true;
    auto it = node->children.end();
    if (it != node->children.begin()) {
        --it;
        last_sibling = false;
    }

    for (auto iter = node->children.begin(); iter != node->children.end(); ++iter) {
        bool is_last = (iter == it);
        display_children(iter->second, level + 1, is_last);
    }
}

void Trie::print_node(int level, trie_node* node) {
    if (level > 0) {
        for (int i = 0; i < level - 1; i++) {
            cout << " │   ";
        }
        cout<<"*";
        cout << "└── ";
    }
    cout << node->data << endl;
}

void Trie::display_children(trie_node* node, int level, bool is_last_sibling) {
    print_node(level, node);

    if (!node->children.empty()) {
        auto it = node->children.end();
        --it;
        for (auto iter = node->children.begin(); iter != node->children.end(); ++iter) {
            display_children(iter->second, level + 1, iter == it);
        }
    }
}
