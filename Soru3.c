#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}
