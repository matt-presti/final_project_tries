## Final Prject: Trie with terminal based Visualizer


Final Project Proposal: Prefix Tree(Trie) with Terminal-Based Visualizer

Overview:
In the current age of abundant digital information, efficiently storing and managing data is a crucial practice. Specifically, data compression to optimize storage and efficient search operations within a data structure are paramount to our current user requirements. This proposal outlines the implementation of a trie, also  known as a prefix tree, using C++. The trie is a hierarchical data structure that is very efficient at handling bodies of text to reduce the memory load of storage by compressing data. It excels at efficient search, insertion, and deletion operations; this makes tries rather useful in areas such as autocomplete systems, spell checkers, and IP routing. This project aims to both implement the trie and also a terminal-based visualization tool that makes the dynamic operations of the trie more clear, serving both educational and practical applications.

Motivation:
As digital communication becomes more and more of a norm in society, the ability to process text efficiently becomes increasingly important. A trie data structure is especially well-suited for managing large datasets and should be used in situations where prefix-based queries are frequent. The concept of prefix trees is inherently visual as it represents characters as nodes in a tree with levels of the tree representing the frequency of that character in the text. For this reason, an interactive visualizer will be of high utility for the user to better understand the innerworkings of things like autocomplete or prefix queries. Tries do not struggle with scalability and perform very well even with very large data sets. A trie maintains efficient performance due to its inherent design, which allows for operations with average complexity O(m), with  'm' being the number of characters length. This optimal performance aspect makes the trie an ideal candidate for applications requiring high-speed text processing.

Implementation Details
The following are my proposed operations along with their complexities. Essential to this process is keeping track of the frequency of each character in the tree and updating this when new strings are added .
-	Insertion: Insert words into the trie, creating new nodes as necessary. Complexity: O(m), m is length of word.
-	Deletion: Remove words from the trie, ensuring proper memory deallocation and maintenance of trie properties. Complexity: O(m).
-	Search: Look for a word in the trie, returning a boolean indicating its presence. Complexity: O(m).
-	Prefix Search: Return a list of all words in the trie that start with a given prefix. This is crucial for autocomplete. Complexity: O(p + n), where 'p' is the length of the prefix and 'n' is the number of child nodes in the subtree under the prefix.
•	-Character frequency Search: Return the frequency of occurrence of a given character in an entire set of text by adding all words to the tree and then running a modified search to find only a single node/character, then returning its frequency. This can be helpful for more broad analysis of text. 
  
Terminal Visualization Tool
A basic  visualization tool will be developed to visually represent the trie. This visualization will be based in the terimal for the sake of simplicity. I considered attempting to build a GUI for the visualization but found this may be challenging and a bit beyond the scope of what we’ve learned to code in this class. The terminal visualization tool will include:

- Real-time visualization of the trie during insertion and deletion operations.
- Highlighting nodes during search operations to demonstrate the process flow.
- Interactive interface allowing users to perform operations and view the trie structure concurrently.
This visualization tool will be instrumental in providing users and students with an interactive learning experience, fostering a deeper understanding of the trie's dynamics.

Learning Hurdles
Anticipated challenges include:
-	Designing an effective visualization that can employ multiple colors for nodes within the constraints of a terminal environment. The visualization will rely mostly on symbols and be somewhat basic in appearance. However, it will be easier to build and less intensive to run given that it is a simple terminal-based visualization. 
-	Handling edge cases, such as deletions that impact multiple child nodes.


Expected Outcomes and Methodology
Initial phases of development will focus on implementing the aforementioned trie operations with test-driven development. The latter phases will prioritize the development of the visualization tool, user interface, and its integration with the trie operations.

Conclusion
The described implementation of a trie data structure with an integrated terminal visualization tool yields significant practical and educational value. It stands to solidify the foundational concepts of efficient handling of text data, prefix queries, compression, and presents them in an accessible format.
![image](https://github.com/matt-presti/final_project_tries/assets/156844474/f64f034f-2b78-451b-9c05-02ac734fe5dc)
