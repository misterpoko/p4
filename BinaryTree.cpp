#include <iostream>
#include "BinaryTree.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
template<class T>
BinaryTree<T>::BinaryTree()
{

}
template<class T>
BinaryTree<T>::~BinaryTree()
{

}
template<class T>
void BinaryTree<T>::insert(T &key)
{

}
template<class T>
void BinaryTree<T>::deleteItem(T &key)
{

}
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{

}
template<class T>
void BinaryTree<T>::preOrder() const
{

}
template<class T>
void BinaryTree<T>::inOrder() const
{

}
template<class T>
void BinaryTree<T>::postOrder() const
{

}
template<class T>
int BinaryTree<T>::getLength() const
{
    return 1;
}


//Needs to stay at the bottom
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;