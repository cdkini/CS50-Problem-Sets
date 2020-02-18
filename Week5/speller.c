// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word) {
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
    int hashVal = word[0] - 97; // Open to add a better hash function later
    return hashVal;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary) {

    FILE *f = fopen(dictionary, "r");
    if (f == NULL) {
        return false;
    }

    char *word = malloc(15); // Allocate memory for word

    while (fscanf(f, "%s", word) != EOF) { // Iterate through file of words until EOF

        node *n = malloc(sizeof(node)); // Create new node for linked list
        if (n == NULL) {
            return false;
        }

        int index = hash(word); // Utilize the hash function to determine the proper hash table index to insert the word into
        strcpy(n->word, word); // Set the new node's word attribute to the word we've read from the file
        n->next = table[index]; // Set n.next to first element of linked list (using index above)
        table[index]->next = n; // Point head to n
    }

    free(word);
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void) {
    unsigned int count = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        node *trav = NULL;
        while (flag) {
            if (table[i] == 0) {
                flag = false;
            } else {
                trav = table[i];
                while (trav != NULL) {
                    count++;
                    trav = trav->next;
                }
            }
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void) {
    // TODO
    return false;
}
