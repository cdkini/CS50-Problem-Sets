#include <ctype.h>
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

    char *newWord = malloc(strlen(word));
    for (int i = 0; word[i]; i++) {
        newWord[i] = tolower(word[i]);
    }

    unsigned int hashVal = hash(newWord);

    if (table[hashVal] == NULL) {
        free(newWord);
        return false;
    }

    node **head = &table[hashVal];
    node *trav = *head;
    while (trav->next != NULL) {
        if (strcmp(trav->word, newWord) == 0) {
            free(newWord);
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
    unsigned int hashVal = word[0] - 97; // Open to add a better hash function later
    return hashVal;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary) {

    FILE *f = fopen(dictionary, "r");

    if (f == NULL) {
        return false;
    }

    char *word = malloc(46); // Allocate memory for word
    while (fscanf(f, "%s", word) != EOF) { // Iterate through file of words until EOF
        node *n = malloc(sizeof(node)); // Create new node for linked list
        if (n == NULL) {
            return false;
        }

        strcpy(n->word, word); // Set the new node's word attribute to the word we've read from the file
        unsigned int index = hash(word); // Utilize the hash function to determine the proper hash table index to insert the word into
        if (table[index] == NULL) {
            table[index] = n;
            free(word);
            return true;
        }
        node **head = &table[index];
        n->next = *head;
        head = &n;
    }

    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void) {
    unsigned int count = 0;

    for (int i = 0; i < N; i++) {
        node **head = &table[i];
        node *trav = *head;
        while (trav->next != NULL) {
            trav = trav->next;
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void) {
    for (int i = 0; i < N; i++) {
        // Traverse linked lists within hash table to free any malloced pointers
        node **head = &table[i];
        node *trav = *head;
        while (trav->next != NULL) {

            trav = trav->next;
        }
    }
    return false;
}
