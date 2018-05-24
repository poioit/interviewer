# Tree Uniqueness, Serialize, Deserialize

* General binary tree
    * Record **preorder + inorde traversal** to reconstruct unique tree.
    * Record **preorder + leaf node** also works.
    * Record **level order + leaf node** also works.
* BST, binary search tree
    * We only need to record **preorder traversal**, because inorder traversal can be found when we sort all node's value.
    * Record **preorder + leaf node** also works.
    * Record **level order + leaf node** also works.
* Replace preorder traversal with postorder traversal also works.
* Level order traversal（leetcode's way to serialize a tree) https://leetcode.com/faq/#binary-tree

* Related problems:
    * Serialize/deserialize trees
        * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
        * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
    * Construct binary from traversal information
        * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
        * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

    * https://leetcode.com/problems/find-duplicate-subtrees/description/