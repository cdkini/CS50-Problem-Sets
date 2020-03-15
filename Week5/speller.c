#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 40001;

// Number of total words
unsigned int wordCount;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word) { // Currently quite broken

    unsigned int index = hash(word);

    if (table[index] == NULL) {
        return false;
    }

    node *trav = table[index];
    while (trav != NULL) {
        if (strcasecmp(trav->word, word) == 0) {
            return true;
        }

        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) { // Checked against REPL and works fine
    unsigned int hash = 5381;
    int c;

    // Iterate through the characters of string
    while ((c = *word++)) {
        // Calculate (hash * 33) + c
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary) {

    FILE *f = fopen(dictionary, "r");
    if (f == NULL) {
        unload();
        return false;
    }

    char word[LENGTH + 1] = {0};
    while (fscanf(f, "%s", word) != EOF) { // Iterate through file of words until EOF
        node *n = malloc(sizeof(node)); // Create new node for linked list
        if (n == NULL) {
            unload();
            return false;
        }

        strcpy(n->word, word); // Set the new node's word attribute to the word we've read from the file
        unsigned int index = hash(word); // Utilize the hash function to determine the proper hash table index to insert the word into
        n->next = table[index];
        table[index] = n;
        wordCount++;
    }

    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void) { // Checked against CS50, this func is correct!
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void) {
    for (int i = 0; i < N; i++) {
        node *trav = table[i];

        while (trav != NULL) {
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }
    return true;
}
