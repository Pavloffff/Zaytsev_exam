#include <iostream>
#include "NTree.h"

int depth(Node *tree)
{
    if (tree == NULL) {
        return 0;
    }
    else {
        int chi = depth(tree->Child);
        int sib = depth(tree->Sibling) - 1;
        return (chi > sib) ? (chi + 1) : (sib + 1);
    }
}

int main(int argc, char const *argv[])
{
    NTree t(5);
    t.Insert(5, 10);
    t.Insert(5, 50);
    t.Insert(50, 11);
    t.Insert(50, 40);
    t.Insert(50, 110);
    t.Insert(10, 100);
    t.Insert(11, 42);
    t.Print();
    std::cout << depth(t.Root) << "\n";
    return 0;
}
