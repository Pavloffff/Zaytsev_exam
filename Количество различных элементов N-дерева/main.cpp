#include <iostream>
#include "NTree.h"
#include "Bst.h"
#include <map>

// пытался добавлять в bst, но что-то пошло не так
// int bstLen(BstNode *b)
// {
//     if (b == nullptr) return 0;
//     int l = bstLen(b->left);
//     int r = bstLen(b->right);
//     return l + r + 1;
// }

// void treeDfsBst(NTreeNode *t, Bst *b)
// {
//     if (t == nullptr) return;
//     b->Insert(t->Key);
//     treeDfsBst(t->Child, b);
//     treeDfsBst(t->Sibling, b);
// }

// int treeCount(NTreeNode *t)
// {
//     Bst *b;
//     treeDfsBst(t, b);
//     return bstLen(b->Root) / 2 + 1;
// }
// поэтому добавлял в map

void treeDfsMap(NTreeNode *t, std::map<int, int> &m)
{
    if (t == nullptr) return;
    m[t->Key] = 1;
    treeDfsMap(t->Child, m);
    treeDfsMap(t->Sibling, m);
}

int treeCount(NTreeNode *t)
{
    std::map<int, int> m;
    treeDfsMap(t, m);
    return m.size();
}


int main(int argc, char const *argv[])
{
    NTree t(5);
    t.Insert(5, 10);
    t.Insert(5, 50);
    t.Insert(50, 11);
    t.Insert(50, 40);
    t.Insert(50, 100);
    t.Insert(10, 100);
    t.Insert(11, 42);
    t.Insert(42, 42);
    t.Print();
    std::cout << treeCount(t.Root) << "\n";
    return 0;
}
