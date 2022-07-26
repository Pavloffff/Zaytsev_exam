#include <iostream>
#include "NTree.h"

// Сложность алгоритма: O(v + e), где v - количество вершин, а e - количество дуг
// начало задачи

// typedef struct _tree {
//     int data;
//     struct _tree *Child;
//     struct _tree *Sibling;
// } Node;

int node_degree(Node *t) {
    if (t == NULL) {
        return 0;
    }
    if (t->Child == NULL) {
        return 0;
    }
    Node *cur = t->Child;
    int cnt = 1;
    while (cur->Sibling != NULL) {
        cnt ++;
        cur = cur->Sibling;
    }
    return cnt;
}

int tree_degree(Node *t) {
    int deg = node_degree(t);
    int sibDeg = 0, chiDeg = 0;
    if (t->Sibling != NULL) {
        sibDeg = tree_degree(t->Sibling);
    }
    if (t->Child != NULL) {
        chiDeg = tree_degree(t->Child);
    }
    if (deg > sibDeg && deg > chiDeg)
        return deg;
    if (sibDeg > chiDeg)
        return sibDeg;
    return chiDeg;
}

// конец задачи

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
    std::cout << tree_degree(t.Root) << "\n";
    return 0;
}
