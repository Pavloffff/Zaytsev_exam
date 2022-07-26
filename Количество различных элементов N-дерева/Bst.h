#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

class BstNode
{
public:
    int key;
    BstNode *left;
    BstNode *right;
};

class Bst
{
public:
    BstNode *Root = nullptr;
    Bst() = default;
    void Print(BstNode *node, int Value);
    void Print();
    BstNode *Insert(BstNode *node, int Value);
    void Insert(int Value);
    BstNode *MinimalBstNode(BstNode *node);
    BstNode *Delete(BstNode *node, int Value);
    void Delete(int Value);
    BstNode *Destroy(BstNode *node);
    ~Bst();
};

BstNode *Bst::Insert(BstNode *node, int Value)
{
    if (node == nullptr) {
        BstNode *tmp = new BstNode;
        tmp->key = Value;
        tmp->left = nullptr;
        tmp->right = nullptr;
        return tmp;
    }
    if (Value < node->key) {
        node->left = Insert(node->left, Value);
    }
    if (Value > node->key) {
        node->right = Insert(node->right, Value);
    }
    return node;
}

void Bst::Insert(int Value)
{
    this->Root = Insert(this->Root, Value);
}

void Bst::Print(BstNode *node, int Value)
{
    if (node != nullptr) {
        for (int i = 0; i < Value; ++i) {
            std::cout << "\t";
        }
        std::cout << node->key << "\n";
        Print(node->left, Value + 1);
        Print(node->right, Value + 1);
    }
}

void Bst::Print()
{
    Print(this->Root, 0);
}

BstNode *Bst::MinimalBstNode(BstNode *node) {
    if (node->left == nullptr) return node;
    return MinimalBstNode(node->left);
}

BstNode *Bst::Delete(BstNode *node, int Value)
{
    if (node == nullptr) return node;
    BstNode *Undertree = nullptr;
    if (Value < node->key) {
        node->left = Delete(node->left, Value);
    } else if (Value > node->key) {
        node->right = Delete(node->right, Value);
    } else if (node->left != nullptr && node->right != nullptr) {
        node->key = MinimalBstNode(node->right)->key;
        node->right = Delete(node->right, node->key);
    } else if (node->left != nullptr) {
        Undertree = node->left;
        delete node;
        node = Undertree;
    } else if (node->right != nullptr) {
        Undertree = node->right;
        delete node;
        node = Undertree;
    } else {
        delete node;
        node = nullptr;
    }
    return node;
}

void Bst::Delete(int Value)
{
    this->Root = Delete(this->Root, Value);
}

BstNode *Bst::Destroy(BstNode *node)
{
    if (node == nullptr) return node;
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }
    if (node->left != nullptr) {
        node->left = Destroy(node->left);
    }
    if (node->right != nullptr) {
        node->right = Destroy(node->right);
    }
    return Destroy(node);
}

Bst::~Bst()
{
    this->Root = Destroy(this->Root);
}


#endif