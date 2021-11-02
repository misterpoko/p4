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
	inserted->right = NULL;
	inserted->left = NULL;
        root = inserted;
        return;
    }
    if (current == NULL)
    {
        NodeType<T> * inserted = new NodeType<T>;
        inserted->key = key;
	inserted->right = NULL;
	inserted->left = NULL;
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
	NodeType<T> * temp = root;
	while (temp != NULL && temp->key != key)
	{
		if (key > temp->key)
			temp = temp->right;
		if (key < temp->key)
			temp = temp->left;	
	} // while
	if (temp == NULL)
	{
		cout << "error dne" << endl;
		return;
	} // if 
	if (temp->right == NULL && temp->left == NULL)
	{
		delete temp;
		return;
	}
	NodeType<T> * temp2 = temp;
	if (temp->right != NULL)
	{
		temp2 = temp->right;
		while (temp2->left != NULL)
			temp2 = temp2->left;
	}
	else
	{
		temp2 = temp->left;
		while (temp2->right != NULL);
			temp2 = temp2->right;
	}
	NodeType<T> temp2P = getP(temp, temp2->key);
	if (temp == root)
	{
		temp2->right = temp->right;
		temp2->left = temp->left;
		temp2 = root;
		delete temp;
	} 
	else
	{
		NodeType<T> tempP = getP(root, temp->key);
		if (tempP.right == temp)
		{
			tempP.right = temp2;
			temp2->right = temp->right;
			temp2->left = temp->left;
			delete temp;
		}
		else
		{
			tempP.left = temp2;
			temp2->right = temp->right;
			temp2->left = temp->left;
			delete temp;
		} // if
	} // if
	if (temp2P.right == temp2)
		temp2P.right == NULL;
	if (temp2P.left == temp2)
		temp2P.left == NULL;
} // deleteItem

/**
 * This method assumes the node exists and this isnt full comments
 */
template<class T>
NodeType<T> BinaryTree<T>::getP(NodeType<T> *current,T &item)
{/*
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
	} // while*/
	// not sure pushing bad message return NULL;
	NodeType<T> *blank = NULL;
	if (current == NULL)
		return *blank;
	if ((current->right != NULL && current->right->key == item) || (current->left != NULL && current->left->key == item))
	{
		return *current;
	}
	else
	{
		if (item > current->key)
		{
			return getP(current->right, item);
		} // if
		if (item < current->key)
		{
			return getP(current->left, item);
		} // if
	} // if
	return *blank;
} // getP
	
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
