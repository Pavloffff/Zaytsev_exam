#include <iostream>
#include "Bst.h"

void deleteLeafs(Node *t) {
    if (t == nullptr) {
        return;
    }
    if (t->left != nullptr) {
        if (t->left->left == nullptr && t->left->right == nullptr) {
            free(t->left);
            t->left = nullptr;
        } else {
            deleteLeafs(t->left);
        }
    }
    if (t->right != nullptr) {
        if (t->right->left == nullptr && t->right->right == nullptr) {
            free(t->right);
            t->right = nullptr;
        } else {
            deleteLeafs(t->right);
        }
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
    deleteLeafs(t.Root);
    t.Print();
    return 0;
}
