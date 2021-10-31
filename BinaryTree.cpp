#include <iostream>
#include "BinaryTree.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{

}

template<class T>
void BinaryTree<T>::insert(T &key)
{
	NodeType<T> *temp = root;
	NodeType<T> *newNode = new NodeType<T>;
	newNode->key = key;
	while (temp != NULL)
	{
		if (newNode->key > temp->key)
		{
			temp = temp->right;
		}
		else if (newNode->key < temp->key)
		{
			temp = temp->left;
		}
		else
		{
			cout << "some error message that its a dup" << endl;
			delete newNode;
			return;
		} // else
	} // while
	temp = newNode;
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
template<class T>
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
