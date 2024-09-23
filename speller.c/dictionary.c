// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
int checker = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
   int hashval = hash(word);
   node *point = table[hashval];

   for (node *temp = point; temp != NULL; temp = temp->next)
    {
        if (strcmp(temp->word, word) == 0)
        {
            return true;
        }
    }
   return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_value = 0;
    int n = strlen(word);

    for (int i = 0; i< n ; i++)
    {
        hash_value += toupper(word[i]);
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *src = fopen(dictionary, "r");

     if (src == NULL)
     {
        perror("Error opening file");
        return 1;
     }

     char word[LENGTH + 1];

     while (fscanf(src, "%s", word) != EOF)
     {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word,word);
        n->next = NULL;

        int hash_value = hash(word);

        if (table[hash_value] == NULL)
        {
            table [hash_value] = n;
        }
        else
        {
            node *current = table[hash_value];
            while (current->next != NULL)
        {
            current = current->next;
        }
            current->next = n;
        }

        }
        fclose(src);
        return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
    }

    checker = 1;
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *temp;
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            temp = current->next;
            free(current);
            current = temp;
        }
    }
    return true;
}
