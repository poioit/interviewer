//https://leetcode.com/problems/implement-trie-prefix-tree/description/
/*
Key points:

1. *next[] can be array of 128 or 26 (if all lowercase, need to - 'a'), or even unordered_map/map.
2. insert(): remember to set isWord = true for the last node.
*/

typedef struct trie {
    trie *next[128];
    bool isWord;
    trie() : isWord(false) {
        memset(next, 0, sizeof(next));
    }
};