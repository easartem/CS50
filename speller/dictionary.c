// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    // Read each word in the file
    char c;
    while (fread(&c, sizeof(char), 1, f))
    {
        // if \n new word, iterate until \n
        // 1. Create space for a new hash table node
        node *new = malloc(sizeof(node));
        // 2. Copy the word into the new node
        new -> word[0] = c;
        // 3. Hash the word to obtain its hash value
        unsigned int hv = hash(&c);
        // 4. Insert the new node into the hash table (using the index specified by its hash value)
        table[hv] = new;
    }
    // Close the dictionary file
    fclose(f);

    return true;
}

void get_word()
{
        // Read each word in the file
    char c;
    while (fread(&c, sizeof(char), 1, f))
    {
        // if \n new word, iterate until \n
        if (c == )
        // 1. Create space for a new hash table node
        node *new = malloc(sizeof(node));
        // 2. Copy the word into the new node
        new -> word[0] = c;
        // 3. Hash the word to obtain its hash value
        unsigned int hv = hash(&c);
        // 4. Insert the new node into the hash table (using the index specified by its hash value)
        table[hv] = new;
    }

}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
