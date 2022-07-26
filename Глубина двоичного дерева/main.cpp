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
    std::cout << depth(t.Root) << "\n";
    return 0;
}
