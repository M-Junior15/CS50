// Implements a dictionary's functionality

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
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashed = hash(word);

    // New block
    if (table[hashed] == NULL)
    {
        return false;
    }
    // End new block

    node *cursor = table[hashed];

    while (strcasecmp(cursor->word, word) != 0)
    {
        if (cursor->next == NULL)
        {
            return false;
        }
        cursor = cursor->next;
    }
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    unsigned int i    = 0;

    for (i = 0; i < LENGTH; ++word, ++i)
    {
        hash = ((hash << 5) + hash) + (*word);
    }
    return hash % N;
}

int cont = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];

    // Try open the file
    FILE *file = fopen(dictionary, "r");

    // Check if it`s null
    if (file == NULL)
    {
        return false;
    }

    // Do a expression until returns EOF (finish of the dictionary)
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        else
        {
            strcpy(n->word, word);
            n->next = NULL;
            int index = hash(word);

            n->next = table[index];
            table[index] = n;
            cont++;

        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return cont;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *temp = *table;
    node *next = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    return true;
}