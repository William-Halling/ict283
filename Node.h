#ifndef NODE_H
#define NODE_H


    /**
     * @class  Node
     * A struct for a node in a binary search tree.
     *
     * @date   May 2024
     * @author William Halling
     */
template<class T>
struct Node
{
        /**
         * @brief constructor for a node
         * @param storedData the data that is to be stored in the Node
         */
    Node(T storedData) : thisData(storedData), left(nullptr), right(nullptr){}

        /**
         * @brief destructor for a node
         * Used to free up resoruces and set the left and right child nodes to null ptr
         */
   ~Node()
    {
        left  = nullptr; ///Left Hand side Node

        right = nullptr; ///Right Hand side Node
    }


    T thisData;  /// The data going into the BST
    Node* left;  /// Left Hand side Node
    Node* right; /// Right Hand side Node
};

#endif // NODE_H
