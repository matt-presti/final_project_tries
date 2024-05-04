#include "../code/trie.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//user interface Menu, options for operations
void displayMenu() {
    cout << "\nTrie Operations Menu:\n";
    cout << "1. Add Word to Trie\n";
    cout << "2. Display Trie\n";
    cout << "3. Check Word Frequency\n";
    cout << "4. Autocomplete Words\n";
    cout << "5. Clear Trie\n";
    cout << "6. Exit\n";
    cout << "Select an option: ";
}

int main() {
    Trie trie;
    string word, prefix;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a word to add: ";
                cin >> word;
                trie.add_word(word);
                cout << "Word added.\n";
                break;
            case 2:
                cout << "Current Trie Structure:\n";
                trie.display(trie.get_root(), 0,"");
                break;
            case 3:
                cout << "Enter a word to check its frequency: ";
                cin >> word;
                cout << "Frequency of '" << word << "': " << trie.frequency(word) << "\n";
                break;
            case 4:
                cout << "Enter prefix for autocomplete: ";
                cin >> prefix;
                {
                    vector<string> completions = trie.auto_complete(prefix);
                    cout << "Autocomplete results: ";
                    for (const auto& w : completions) {
                        cout << w << " ";
                    }
                    cout << "\n";
                }
                break;
            case 5:
                trie.clear(trie.get_root());
                trie = Trie(); // Reinitialize the trie after clearing
                cout << "Trie cleared.\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
