#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

class Node
{
public:
    int key;
    Node *left;
    Node *right;
};

class Bst
{
public:
    Node *Root = nullptr;
    Bst() = default;
    void Print(Node *node, int Value);
    void Print();
    Node *Insert(Node *node, int Value);
    void Insert(int Value);
    Node *MinimalNode(Node *node);
    Node *Delete(Node *node, int Value);
    void Delete(int Value);
    Node *Destroy(Node *node);
    ~Bst();
};

Node *Bst::Insert(Node *node, int Value)
{
    if (node == nullptr) {
        Node *tmp = new Node;
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

void Bst::Print(Node *node, int Value)
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

Node *Bst::MinimalNode(Node *node) {
    if (node->left == nullptr) return node;
    return MinimalNode(node->left);
}

Node *Bst::Delete(Node *node, int Value)
{
    if (node == nullptr) return node;
    Node *Undertree = nullptr;
    if (Value < node->key) {
        node->left = Delete(node->left, Value);
    } else if (Value > node->key) {
        node->right = Delete(node->right, Value);
    } else if (node->left != nullptr && node->right != nullptr) {
        node->key = MinimalNode(node->right)->key;
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

Node *Bst::Destroy(Node *node)
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