#include <iostream>
#include "Bst.h"

int depth(Node *tree)
{
	if (tree == NULL) {
		return 0;
	}
	else {
		int left_depth = depth(tree->left);
		int right_depth = depth(tree->right);
		return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);
	}
}

Node *last;
Node *lastParent;

void getLastLeafAndParent(Node *tree, int level, Node *parent)
{
    if (tree == nullptr) return;
    if (level == 1) {
        last = tree;
        lastParent = parent;
    }
    getLastLeafAndParent(tree->left, level - 1, tree);
    getLastLeafAndParent(tree->right, level - 1, tree);
}

void deleteLastLeaf(Bst *Btree)
{
    Node *tree = Btree->Root;
    int level = depth(tree);
    getLastLeafAndParent(tree, level, nullptr);
    if (last && lastParent) {
        Btree->Delete(last->key);
    }
}

int main(int argc, char const *argv[])
{
    Bst t;
    t.Insert(8);
    t.Insert(3);
    t.Insert(10);
    t.Insert(1);
    t.Insert(6);
    t.Insert(14);
    t.Insert(4);
    t.Insert(7);
    t.Insert(13);
    t.Print();
    deleteLastLeaf(&t);
    t.Print();
    return 0;
}
