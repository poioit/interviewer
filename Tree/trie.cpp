//https://leetcode.com/problems/implement-trie-prefix-tree/description/
/*
Key points:

1. *next[] can be an array of 128 or 26 (if all lowercase, need to - 'a'), or
   you can even use unordered_map/map for next(childs).
2. insert(): during traversal of one string, remember to set isWord = true for the last node(char) when the string ends.
3. Another implementations is to replace "bool isWord" with a "string str", where non-empty string means there's a
   word ends here, then we don't need to record the chars on the traversal path, just return str when it's a match.
*/

typedef struct trie {
    trie *next[128];
    bool isWord;
    trie() : isWord(false) {
        memset(next, 0, sizeof(next));
    }
};

// in this way, non-empty string means a word ends here, and
// we don't need to record the chars on the traversal path.
typedef struct trie {
    trie *next[128];
    string str;
    trie() : isWord(false) {
        memset(next, 0, sizeof(next));
    }
};
