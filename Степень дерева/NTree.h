#ifndef NTREE_H
#define NTREE_H

#include <iostream>
#include <string>

class Node
{
public:
    int Key;
    Node *Child;
    Node *Sibling;
    Node *Parent;
};

class NTree
{
public:
    Node *Root;
    Node *Create(int Value);
    void Print(Node *node, int Value);
    Node *Find(Node *node, int Value);
    void Destroy(Node *node);
    NTree(int Value);
    void Print();
    void Insert(int ParentValue, int Value);
    ~NTree();
};

Node *NTree::Create(int Value)
{
    Node *node = new Node;
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

void NTree::Print(Node *node, int Value)
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

Node *NTree::Find(Node *node, int Value)
{
    if (node == nullptr) return nullptr;
    if (node->Key == Value) return node;
    Node *cur = nullptr;
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
    Node *res = Find(this->Root, ParentValue);
    if (res == nullptr) return;
    Node *resParent = res;
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

void NTree::Destroy(Node *node)
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