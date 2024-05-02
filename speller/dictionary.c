// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

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
    while (table[hv]->next != NULL)
    {
        // 3. Check if the words are the same
        if (strcasecmp(table[hv]->word, word)) // case-insensitive comparaison
        {
            return true;
        }
    }
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
    else
    {
        printf("Could open %s.\n", dictionary);
    }

    // instantiate hash table size N=26 (A-Z)
    char letter = 65;
    for (int i = 0; i < N; i++)
    {
        printf("%c  %d\n", letter, letter);
        node *base = malloc(sizeof(node));
        base->word[0] = letter;
        base->next = NULL;
        table[i] = base;
        letter = letter + 1;
    }

    // Read each word in the file
    check_dict_init();
    get_word(f);

    // Close the dictionary file
    fclose(f);

    return true;
}

void check_dict_init(void)
{
    for (int j = 0; j < N; j++)
    {
        printf("%c", table[j]->word[0]);
    }
    printf("\n");
    return;
}

void get_word(FILE *f)
{
    // Read each word in the file
    char c;
    int i =0;
    node *new;
    size_dict = 0;

    while (fread(&c, sizeof(char), 1, f))
    {
        // if letter
        if (isalpha(c))
        {
            // if first letter
            if (i < 1)
            {
                // 1. Create space for a new hash table node
                new = malloc(sizeof(node));
                // 2. Copy the first char into the new node
                new -> word[0] = c;
                new->next = NULL;
                // 3. Increase the letter counter
                i++;
            }
            else if (i > 1)
            {
                // keep copying the following letter of the word
                new -> word[i] = c;
                i++;
            }
        }
        // if end of word
        if (isspace(c))
        {
            // Hash the word to obtain its hash value
            unsigned int hv = hash(&(new->word[0]));
            // Insert the new node into the hash table (using the index specified by its hash value)
            table[hv]->next = new;
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
    // free last element
    free(table);
    return true;


}

void free_node(node *block)
{
        if (block == NULL)
        {
            return;
        }
        else if (block->next != NULL)
        {
            free_node(block->next);
        }
        else
        {
            free(block);
        }
}
