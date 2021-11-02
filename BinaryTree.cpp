#include <iostream>
#include "BinaryTree.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	length = 0;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{

}

template<class T>
void BinaryTree<T>::insertPt2(T &key, NodeType<T> *current, NodeType<T> *previous)
{
	if (root == NULL)
    {
        NodeType<T> * inserted = new NodeType<T>;
        inserted->key = key;
        root = inserted;
        return;
    }
    if (current == NULL)
    {
        NodeType<T> * inserted = new NodeType<T>;
        inserted->key = key;
        if (key > previous->key)
        {
            previous->right = inserted;
            return;
        } // if
        if (key < previous->key)
        {
            previous->left = inserted;
            return;
        }
        return;
    }
    if (key > current->key)
    {
        insertPt2(key, current->right, current);
    }
    if (key < current->key)
    {
        insertPt2(key, current->left, current);
    }
    if (key == current->key)
    {
        cout << "some error message dup" << endl;
    }
}

template<class T>
void BinaryTree<T>::insert(T &key)
{
	insertPt2(key, root, NULL);
} // insert

template<class T>
void BinaryTree<T>::deleteItem(T &key)
{
/*	NodeType<T> *temp = root;  // this is the finder node
	NodeType<T> *temp2 = NULL; // this node lags behind temp
	int found = 0;
	while (!found)
	{
		temp2 = temp;
		if (key > temp->key)
		{
			temp = temp->right;
		}
		if (key < temp->key)
		{
			temp = temp->left;
		} // if
		if (key == temp->key)
		{
			found = 1;
		} // if
		if (temp == NULL)
		{
			cout << "some error message unfindable" << endl;
			return;
		} // if
	} // while
	NodeType<T> *record = temp;
	int right = 0;
	found = 0;	
	if (temp->key < temp2->key)
	{
		right = 1;	
	} // if
	if (temp == root)
	{
		if (temp->left == NULL)
		{
			root = temp->right;
			delete temp;
			return;
		} // if
		if (temp->right == NULL)
		{
			root = temp->left;
			delete temp;
			return;
		} // if
	} // if
	if (temp->right == NULL && temp->left == NULL)
	{
		delete temp;
		return;
	} // if
	while (!found)
	{
		if (right && record ->right != NULL)
		{
			record = record->right 		
	} // while
*/		
} // deleteItem

/**
 * This method assumes the node exists and this isnt full comments
 */
/*template<class T>
NodeType<T> BinaryTree<T>::getP(T &item)
{
	NodeType<T> *temp = root;
	if (item == root->key)
	{	
		//return NULL;
	}
	int found = 0;
	while (!found)
	{
		if (item > temp->key)
		{
			if (temp->right->key == item)
			{
				return *temp;
			}
			temp = temp->right;
		} // if
		if (item < temp->key)
		{
			if (temp->left->key == item)
			{
				return *temp;
			} 
			temp = temp->left;
		} // if
		if (temp == NULL)
		{
			found = 1;
			// something is wrong this is here to prevent potential infinite loops
		} // if
	} // while
	// not sure pushing bad message return NULL;
} // getP*/
	
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
	NodeType<T> * temp = root;
	int beenFound = 0;
	while (!beenFound)
	{
		if (item > temp->key)
		{
			temp = temp->right;
		}
		if (item < temp->key)
		{
			temp = temp->left;
		} // if
		if (item == temp->key)
		{
			found = true;
			beenFound = 1;
		} // if
		if (temp == NULL)
		{
			found = false;
			beenFound = 1;
		} // if
	} // while
}
template<class T>
void  BinaryTree<T>::preOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	}
}
template<class T>
void BinaryTree<T>::preOrder() const
{
	preOrderPrint(root);
}

template<class T>
void BinaryTree<T>::inOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		inOrderPrint(root->left);
		cout << root->key << " ";
		inOrderPrint(root->right);
	}
}

template<class T>
void BinaryTree<T>::inOrder() const
{
	inOrderPrint(root);
}

template<class T>
void BinaryTree<T>::postOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		postOrderPrint(root->left); 
		postOrderPrint(root->right);
		cout << root->key << " ";
	}
}
template<class T>
void BinaryTree<T>::postOrder() const
{
	postOrderPrint(root);
}

template<class T>
int BinaryTree<T>::getLength() const
{
    return length;
}

template<class T>
void BinaryTree<T>::getNumSingleParent()
{

}

template<class T>
int BinaryTree<T>::getNumLeafNodes()
{
	return 1;
}

template<class T>
int BinaryTree<T>::getSumOfSubtrees()
{
	return 1; 
}
//Needs to stay at the bottom
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
