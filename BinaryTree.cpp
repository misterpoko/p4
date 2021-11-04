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
  numberOfParents = 0;
  numberOfLeafs = 0; 
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
void BinaryTree<T>::getPredecessor(NodeType<T> *root, T &data)
{	
	while(root->right != NULL)
	{
		root = root->right;
	}
	data = root->key;
	
}

template<class T>
void BinaryTree<T>::DeleteNode(NodeType<T> *root, T &key)
{
	T data;
	NodeType<T> *tempPtr;
	tempPtr = root;
	if(root->left == NULL)
	{
		root = root->left;
		delete(tempPtr);
		tempPtr = NULL;
	}
	else if(root->right == NULL)
	{
		root = root->right; 
		delete(tempPtr);
		tempPtr = NULL;
	}
	else
	{
		getPredecessor(root->left, data);\
		root->key = data;
		deleteHelper(root->left, data);
	}
}


template<class T>
void BinaryTree<T>::deleteHelper(NodeType<T> *root, T &key)
{
	if(key<root->key)
	{
		deleteHelper(root->left, key);
	}
	else if(key>root->key)
	{
		deleteHelper(root->right, key);
	}
	else //Node found
	{
		cout << "Found" << endl;
		DeleteNode(root, key);
	}
}


template<class T>
void BinaryTree<T>::deleteItem(T &key)
{
	deleteHelper(root,key);
	/*NodeType<T> * temp = root;
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
		temp = NULL;
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
		temp = NULL;
		return;
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
	temp = NULL;*/
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
	} //if
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

void uo()
{
	write(1,"error", 6);
}

template<class T>
void retrieveHelper(NodeType<T> *root, T &item, bool &found)
{
   if( root == NULL )
   {
     return; 
   }// if
   else if( root->key == item )
   {
     found = true;
     return;
   }// else if
   retrieveHelper(root->left,item, found); 
   retrieveHelper(root->right,item, found);
}
 
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
  retrieveHelper(root, item, found);
	/*NodeType<T> * temp = root;
	int beenFound = 0;
	while (!beenFound)
	{
    if (temp == NULL)
		{
			found = false;
			beenFound = 1;
		} //if
		if (item > temp->key)
		{
			temp = temp->right;
		} //if
		if (item < temp->key)
		{
			temp = temp->left;
		} // if
		if (item == temp->key)
		{
			found = true;
			beenFound = 1;
		} // if
	} // while*/
   
}// retrieve

template<class T>
void  BinaryTree<T>::preOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	} //if
} // preOrderPrint
template<class T>
void BinaryTree<T>::preOrder() const
{
	preOrderPrint(root);
} // preOrder

template<class T>
void BinaryTree<T>::inOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		inOrderPrint(root->left);
		cout << root->key << " ";
		inOrderPrint(root->right);
	} //if
}// inOrderPrint

template<class T>
void BinaryTree<T>::inOrder() const
{
	inOrderPrint(root);
} // inOrder

template<class T>
void BinaryTree<T>::postOrderPrint(NodeType<T> *root) const
{
	if (root != NULL)
	{
		postOrderPrint(root->left); 
		postOrderPrint(root->right);
		cout << root->key << " ";
	} //if
} // postOrderPrint
template<class T>
void BinaryTree<T>::postOrder() const
{
	postOrderPrint(root);
} // postOrder

template<class T>
int BinaryTree<T>::getLength() const
{
  return length;
} //getLength

template<class T>
void BinaryTree<T>::getNumSingleParent()
{
  getNumSingleParentHelper(root);
  cout << "Number of single parents: " << numberOfParents << endl;
  numberOfParents = 0;
} //getNumSingleParent

template<class T>
void BinaryTree<T>::getNumSingleParentHelper(NodeType<T> *root)
{
  if(root == NULL)
  {
    return;
  }//if
  else if (root->left != NULL && root->right == NULL || root->left == NULL && root->right != NULL)
  {
    numberOfParents++;
  }//if
  getNumSingleParentHelper(root->left);
  getNumSingleParentHelper(root->right);
} // getNumSingleParentHelper

template<class T>
void BinaryTree<T>::getNumLeafNodesHelper(NodeType<T> *root)
{
  if( root == NULL )
  {
    return;
  }//if
  else if( root->left == NULL && root->right == NULL ) 
  {
    numberOfLeafs++;
  } // if
  getNumLeafNodesHelper(root->left); 
  getNumLeafNodesHelper(root->right);
} //getNumLeafNodesHelper


template<class T>
void BinaryTree<T>::getNumLeafNodes()
{
  getNumLeafNodesHelper(root);
  cout << "Number of leaf nodes: " << numberOfLeafs << endl;
  numberOfLeafs = 0;
} //getNumLeafNodes

template<class T>
void BinaryTree<T>::getSumOfSubtreesHelper(NodeType<T> *root,T &item, bool &present )
{
   T sumOfSubTrees;
   if( root == NULL )
   {
     return; 
   }// if
   else if( root->left != NULL && root->right != NULL && root->key == item )
   {
     sumOfSubTrees = root->left->key +  root->right->key;
     cout << "Sum of Subtrees: " << sumOfSubTrees << endl;
     present = true;
   }// else if
   getSumOfSubtreesHelper(root->left,item, present); 
   getSumOfSubtreesHelper(root->right,item, present);
} //getSumOfSubtreesHelper

template<class T>
void BinaryTree<T>::getSumOfSubtrees(T &item)
{
  bool present = false;
	getSumOfSubtreesHelper(root, item, present); 
  if ( present == false)
  {
    cout << "Item no present or isnt a subtree" << endl; 
  } // if
} //getSumOfSubtrees

//Needs to stay at the bottom
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
