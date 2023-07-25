#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a trie node
typedef struct trieNode {
    char value;
    int isWord;
    struct trieNode* children[26];
} TrieNode;

// Define a function to create a new trie node
TrieNode* createTrieNode(char value) {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->value = value;
    node->isWord = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Define a function to insert a word into the trie
void insert(TrieNode* root, char* word) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createTrieNode(word[i]);
        }
        current = current->children[index];
    }
    current->isWord = 1;
}

// Define a function to search for a word in the trie
int search(TrieNode* root, char* word) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->isWord;
}

// Define a main function to test the trie implementation
int main() {
    // Create a new root node for the trie
    TrieNode* root = createTrieNode('\0');

    // Insert some words into the trie
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "cherry");
    insert(root, "chris");

    // Search for some words in the trie
    printf("Is 'apple' in the trie? %d\n", search(root, "apple"));
    printf("Is 'orange' in the trie? %d\n", search(root, "orange"));
    printf("Is 'chris' in the trie? %d\n", search(root, "chris"));

    // Free the memory used by the trie
    free(root);

    return 0;
}
