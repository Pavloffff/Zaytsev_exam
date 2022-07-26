#include <iostream>
#include "NTree.h"
#include <map>

int treeLen(NTreeNode *t)
{
	if (t == NULL) {
		return 0;
	}
	int chi = treeLen(t->Child);
	int sib = treeLen(t->Sibling);

	return chi + sib + 1;
}

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
    return treeLen(t) - m.size();
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
