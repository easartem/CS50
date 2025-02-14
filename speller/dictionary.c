// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
// const unsigned int N = 26;
const unsigned int N = 52;

int size_dict;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // 1. Hash the word to obtain its hash value
    int hv = hash(word);
    // 2. Search the hash table at the location specified by the word’s hash value
    node *cursor = table[hv];
    while (cursor != NULL)
    {
        // 3. Check if the words are the same
        if (strcasecmp(cursor->word, word) == 0) // case-insensitive comparaison
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Print the length of each block of the dict
void size_block(void)
{
    for (int i = 0; i < N; i++)
    {
        int cpt = 0;
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cpt++;
            cursor = cursor->next;
        }
        printf("index : %i, size : %i\n", i, cpt);
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int index = toupper(word[0]) - 'A';
    if (index > 0)
    {
        index = index + 1;
    }
    index = index + (strlen(word) % 2);
    return index;
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
    else
    {
        printf("Could open %s.\n", dictionary);
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Read each word in the file
    get_word(f);

    // Close the dictionary file
    fclose(f);

    return true;
}

void get_word(FILE *f)
{
    // Read each word in the file
    char c;
    int i = 0;
    node *new;
    size_dict = 0;

    while (fread(&c, sizeof(char), 1, f))
    {
        // if letter
        if ((isalpha(c)) | (c == 39))

        {
            // if first letter
            if (i < 1)
            {
                // 1. Create space for a new hash table node
                new = malloc(sizeof(node));
                if (new == NULL)
                {
                    printf("Allocation error of node during loading\n");
                    return;
                }
                // 2. Copy the first char into the new node
                new->word[0] = c;
                new->next = NULL;
                // 3. Increase the letter counter
                i++;
            }
            else if (i >= 1)
            {
                // keep copying the following letter of the word
                new->word[i] = c;
                i++;
            }
        }
        // if end of word
        if (isspace(c))
        {
            new->word[i] = '\0';
            // Hash the word to obtain its hash value
            unsigned int hv = hash(&(new->word[0]));
            // Insert the new node into the hash table (using the index specified by its hash value)
            if (table[hv] == NULL)
            {
                table[hv] = new;
            }
            else
            {
                new->next = table[hv];
                table[hv] = new;
            }
            i = 0;
            size_dict++;
        }
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (size_dict == 0)
    {
        return 0;
    }
    else
    {
        return size_dict;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        free_node(table[i]);
    }
    return true;
}

void free_node(node *block)
{
    if (block == NULL)
    {
        return;
    }
    else
    {
        free_node(block->next);
        free(block);
    }
}
