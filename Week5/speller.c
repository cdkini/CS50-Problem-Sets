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
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if (f == NULL) {
        return false;
    }
    char *word = malloc(10); // Allocate memory for word
    while (fscanf(f, "%s", word) != EOF) { // Iterate through file of words
        node *n = malloc(sizeof(node)); // Create new node for linked list
        if (n == NULL) {
            return false;
        }
        strcpy(n->word, word); // Set the new node's word attribute to the word we've read from the file
        n->next = NULL;
        int index = hash(n->word); // Utilize the hash function to determine the proper hash table index to insert the word into
        // Set n.next to first element of linked list (using index above)
        n->next = table[index][0];
        table[index].next = n;
        // Point head to n
    }


    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
