// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/trie.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class TrieTest : public ::testing::Test {
protected:

Trie trie; //create Trie instance to use for test, build below

  //setup with various words that share prefixes
   void SetUp() override {
    trie.add_word("jello");
    trie.add_word("just");
    trie.add_word("justin");
    trie.add_word("jejunum");
    trie.add_word("jellyfish");
    trie.add_word("hello");
    trie.add_word("helium");
    trie.add_word("helicopter");
    trie.add_word("hellbent");
    trie.add_word("helper");
    trie.add_word("holy");
    trie.add_word("jello");
    trie.add_word("just");
    trie.add_word("jello");

   }

   void TearDown() override {}
};

TEST_F(TrieTest, FindsWords) {
    ASSERT_TRUE(trie.lookup("hello"));
    ASSERT_TRUE(trie.lookup("helium"));
    ASSERT_FALSE(trie.lookup("hero"));
    ASSERT_TRUE(trie.lookup("justin"));
    ASSERT_TRUE(trie.lookup("jejunum"));
    ASSERT_FALSE(trie.lookup("jealous"));
    ASSERT_FALSE(trie.lookup("jeffrey"));
}

TEST_F(TrieTest,FinishWords) {
    vector<string> hel = trie.auto_complete("hel");
    //check all elements were added
    ASSERT_EQ(hel.size(), 5);
    //check that string is in vector
    //find iterator should not equal final index!
    ASSERT_NE(find(hel.begin(), hel.end(), "hello"), hel.end());
    ASSERT_NE(find(hel.begin(), hel.end(), "helium"), hel.end());
    ASSERT_NE(find(hel.begin(), hel.end(), "helicopter"), hel.end());
    ASSERT_NE(find(hel.begin(), hel.end(), "hellbent"), hel.end());
    ASSERT_NE(find(hel.begin(), hel.end(), "helper"), hel.end());

    //test with "jel"
     vector<string> jel = trie.auto_complete("jel");
    ASSERT_EQ(jel.size(), 2);
    ASSERT_NE(find(jel.begin(), jel.end(), "jello"), jel.end());
    ASSERT_NE(find(jel.begin(), jel.end(), "jellyfish"), jel.end());
    ASSERT_EQ(find(jel.begin(), jel.end(), "jejunum"), jel.end());

    //test with gibberish
    vector<string> gib = trie.auto_complete("xjkwoertysl");
    ASSERT_EQ(gib.size(),0);
  
}

TEST_F(TrieTest, FindCharacter) {
    // Test finding characters in the middle of words

    //test e
    trie_node* node_e = trie.find_character('e');
    ASSERT_EQ(node_e, nullptr);
  
    //test t
    trie_node* node_t = trie.find_character('t');
    ASSERT_EQ(node_t, nullptr);
 

    //test h
    trie_node* node_h = trie.find_character('h');
    ASSERT_TRUE(node_h != nullptr);
    ASSERT_FALSE(node_h->is_word);
  

    //test x
    trie_node* node_x = trie.find_character('x');
    ASSERT_EQ(node_x, nullptr);
}

TEST_F(TrieTest, Frequency) {
    // Test frequency of words
    ASSERT_EQ(trie.frequency("jello"),3);
    ASSERT_EQ(trie.frequency("just"), 2);
    ASSERT_EQ(trie.frequency("helicopter"), 1);
    ASSERT_EQ(trie.frequency("hello"), 1);
    ASSERT_EQ(trie.frequency("world"), 0);
}

