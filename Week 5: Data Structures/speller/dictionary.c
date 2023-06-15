// Implements a dictionary's functionality.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Declare root node.
node *root=NULL;

// Declare counters.
unsigned int *ptr_counter;
unsigned int word_counter;


//creates a new node
//returns a pointer to a new node

struct node *getNewNode(void)
{
    struct node *newNode=(struct node*)calloc(1, sizeof(struct node));
     if(newNode==NULL)
    {
        printf("Could not access memory\n");
        unload();
        return false;
    }

// Initialize member bool is_word to false.
    newNode->is_word=false;

    return newNode;
}

// Deletes nodes from trie, called recursively to unload dictionary.

void freeTrie(node *temp)
{
    for(int i=0; i<CHILDREN; i++)
    {
      if(temp->children[i]!=NULL)
      {
        freeTrie(temp->children[i]);
      }
    }
    free(temp);

 return;
}

// Returns true if word is in dictionary, else false.

bool check(const char *word)
{
// Declare temp node pointer for traversing and initialize trav to point to same address as root.
    node *temp=root;

    int index=0;
    const char *tword=word;


    for(int i=0, n=strlen(word); i<n; i++)
    {
// Calculate alphabetical index/index for aphostrophe of a character in a word corresponding to a pointer in children array.
        if(isalpha(tword[i]))
          index=tolower(tword[i])-'a';
        else
            index=APOSTROPHE;

        if(temp->children[index]==NULL)
            return false;
        else
            temp=temp->children[index];
    }

    if(temp->is_word==true)
        return true;
    else
        return false;

}

// Loads dictionary into memory.
bool load(const char *dictionary)
{
// Opens dictionary. Returns true if successful, else false.
    FILE *fpd=fopen(dictionary, "r");
    if(fpd==NULL)
    {
        printf("Could not open %s\n.", dictionary);
        return false;
    }

// Create and malloc memory for root node.
    root=getNewNode();

// Declare temp node pointer for traversing.
    node *temp=NULL;

// Declare word to be read from dictionary.
    char dword[47];

// Initialize index to 0.
    int index=0;

// Initialize word counter to 0.
    word_counter=0;

// Scan dictionary word by word until the EOF is reached.
    while(fscanf(fpd, "%s", dword)!=EOF)
    {
// Traverse starting from root node for each word.
        temp=root;

// Calculates the length of the word.
        int n=strlen(dword);

//Iterates over each character in the word.
        for (int i=0; i<n; i++)
        {
//Calculate alphabetical index/index for aphostrophe of a character in a word corresponding to pointer in children array
            if(isalpha(dword[i]))
                index=tolower(dword[i])-'a';
            else
                index=APOSTROPHE;

            if(temp->children[index]==NULL)
            {
//Get a new node if pointer at children[index] in NULL
                struct node* newNode=getNewNode();

//Check if current character of a word is the last character of the word; if so, set is_word to true
                if(n-1==i)
                {
                    newNode->is_word=true;
                    word_counter++;
                }
                temp->children[index]=newNode;
                temp=newNode;
            }
//Check if current character of a word is the last character of the word; if so, set is_word to true
            else
            {
                 if (n-1==i)
                 {
                    temp->is_word=true;
                    word_counter++;
                 }
                 temp=temp->children[index];
            }
        }
    }

// Closes dictionary.
    fclose(fpd);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded.
unsigned int size(void)
{
    ptr_counter=&word_counter;
    return word_counter;
}

// Unloads dictionary from memory. Returns true if successful else false.
bool unload(void)
{
// Declares temp node pointer for traversing.
    node *trav=root;

// Calls function to delete nodes in trie.
    freeTrie(trav);

    return true;

}