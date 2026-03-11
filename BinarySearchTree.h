#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include "Statistics.h"

/***
 * @brief Forward declare the Statistics class to use in function pointers.
 */
class Statistics;

/**
 * @brief Function pointer type for node processing
 */
template<class T>
using voidFuncPointer = void(*)(const T&, int, int, Statistics&);

/**
 * @class BinarySearchTree
 * @brief A templated Binary Search Tree class
 * @author William Halling
 * @date May 2024
 * @version 1.0
 */
template<class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool isEmpty() const;

    void insert(const T& newData);
    Node<T>* search(const T& findData) const;

    void inOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats);
    void preOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats);
    void postOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats);

    Node<T>* getRoot() const;

private:
    Node<T>* rootNode;

    void insert(Node<T>*& currentNode, const T& newData) const;
    Node<T>* search(Node<T>* const& currentNode, const T& findData) const;

    void destroyTree(Node<T>*& thisNode);

    void inOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const;
    void preOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const;
    void postOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const;

    void clear(Node<T>*& currentNode, const T& removeData);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() : rootNode(nullptr) {}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    destroyTree(rootNode);
    rootNode = nullptr;
}

template<class T>
bool BinarySearchTree<T>::isEmpty() const
{
    return rootNode == nullptr;
}

template<class T>
Node<T>* BinarySearchTree<T>::getRoot() const
{
    return rootNode;
}

template<class T>
void BinarySearchTree<T>::insert(const T& newData)
{
    insert(rootNode, newData);
}

template<class T>
Node<T>* BinarySearchTree<T>::search(const T& findData) const
{
    return search(rootNode, findData);
}

template<class T>
void BinarySearchTree<T>::insert(Node<T>*& currentNode, const T& newData) const
{
    if(currentNode == nullptr)
    {
        currentNode = new Node<T>(newData);
        return;
    }

    if(newData < currentNode->thisData)
        insert(currentNode->left, newData);
    else if(newData > currentNode->thisData)
        insert(currentNode->right, newData);
}

template<class T>
Node<T>* BinarySearchTree<T>::search(Node<T>* const& currentNode, const T& findData) const
{
    if(currentNode == nullptr) return nullptr;
    if(currentNode->thisData == findData) return currentNode;
    if(findData < currentNode->thisData) return search(currentNode->left, findData);
    return search(currentNode->right, findData);
}

template<class T>
void BinarySearchTree<T>::inOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats)
{
    inOrderTraverse(rootNode, processFunction, month, year, stats);
}

template<class T>
void BinarySearchTree<T>::inOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const
{
    if(currentNode != nullptr)
    {
        inOrderTraverse(currentNode->left, processFunction, month, year, stats);
        processFunction(currentNode->thisData, month, year, stats);
        inOrderTraverse(currentNode->right, processFunction, month, year, stats);
    }
}

template<class T>
void BinarySearchTree<T>::preOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats)
{
    preOrderTraverse(rootNode, processFunction, month, year, stats);
}

template<class T>
void BinarySearchTree<T>::preOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const
{
    if(currentNode != nullptr)
    {
        processFunction(currentNode->thisData, month, year, stats);
        preOrderTraverse(currentNode->left, processFunction, month, year, stats);
        preOrderTraverse(currentNode->right, processFunction, month, year, stats);
    }
}

template<class T>
void BinarySearchTree<T>::postOrderTraverse(voidFuncPointer<T> processFunction, int month, int year, Statistics& stats)
{
    postOrderTraverse(rootNode, processFunction, month, year, stats);
}

template<class T>
void BinarySearchTree<T>::postOrderTraverse(Node<T>*& currentNode, voidFuncPointer<T> processFunction, int month, int year, Statistics& stats) const
{
    if(currentNode != nullptr)
    {
        postOrderTraverse(currentNode->left, processFunction, month, year, stats);
        postOrderTraverse(currentNode->right, processFunction, month, year, stats);
        processFunction(currentNode->thisData, month, year, stats);
    }
}

template<class T>
void BinarySearchTree<T>::destroyTree(Node<T>*& thisNode)
{
    if(thisNode != nullptr)
    {
        destroyTree(thisNode->left);
        destroyTree(thisNode->right);
        delete thisNode;
        thisNode = nullptr;
    }
}

template<class T>
void BinarySearchTree<T>::clear(Node<T>*& currentNode, const T& removeData)
{
    if(currentNode == nullptr) return;

    if(currentNode->thisData == removeData)
    {
        delete currentNode;
        currentNode = nullptr;
        return;
    }

    if(removeData < currentNode->thisData)
        clear(currentNode->left, removeData);
    else
        clear(currentNode->right, removeData);
}

#endif // BINARYSEARCHTREE_H