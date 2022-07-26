#ifndef NTREE_H
#define NTREE_H

#include <iostream>
#include <string>

class NTreeNode
{
public:
    int Key;
    NTreeNode *Child;
    NTreeNode *Sibling;
    NTreeNode *Parent;
};

class NTree
{
public:
    NTreeNode *Root;
    NTreeNode *Create(int Value);
    void Print(NTreeNode *node, int Value);
    NTreeNode *Find(NTreeNode *node, int Value);
    void Destroy(NTreeNode *node);
    NTree(int Value);
    void Print();
    void Insert(int ParentValue, int Value);
    ~NTree();
};

NTreeNode *NTree::Create(int Value)
{
    NTreeNode *node = new NTreeNode;
    node->Key = Value;
    node->Child = nullptr;
    node->Sibling = nullptr;
    node->Parent = nullptr;
    return node;
}

NTree::NTree(int Value)
{
    this->Root = Create(Value);
}

void NTree::Print(NTreeNode *node, int Value)
{
    if (node != nullptr) {
        for (int i = 0; i < Value; i++) {
            std::cout << "|    ";
        }
        std::cout << node->Key << "\n";
        if (node->Child != nullptr) {
            Print(node->Child, Value + 1);
        }
        Print(node->Sibling, Value);
    }
}

void NTree::Print()
{
    Print(this->Root, 0);
}

NTreeNode *NTree::Find(NTreeNode *node, int Value)
{
    if (node == nullptr) return nullptr;
    if (node->Key == Value) return node;
    NTreeNode *cur = nullptr;
    if (node->Child) {
        cur = Find(node->Child, Value);
        if (cur != nullptr) {
            return cur;
        }
    }
    if (node->Sibling) {
        cur = Find(node->Sibling, Value);
        if (cur != nullptr) {
            return cur;
        }
    }
    return nullptr;
}

void NTree::Insert(int ParentValue, int Value)
{
    NTreeNode *res = Find(this->Root, ParentValue);
    if (res == nullptr) return;
    NTreeNode *resParent = res;
    if (res->Child == nullptr) {
        res->Child = Create(Value);
        res->Child->Parent = res;
        return;
    }
    res = res->Child;
    while (res->Sibling != nullptr) {
        res = res->Sibling;
    }
    res->Sibling = Create(Value);
}

void NTree::Destroy(NTreeNode *node)
{
    if (node != nullptr) {
        if (node->Child != nullptr) {
            Destroy(node->Child);
        }
        if (node->Sibling != nullptr) {
            Destroy(node->Sibling);
        }
    }
    delete node;
}

NTree::~NTree()
{
    Destroy(this->Root);
}

#endif