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
  first = true;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	destroy(root);
	root = NULL;
}

template<class T>
void BinaryTree<T>::destroy (NodeType<T> *node)
{
	if (node != NULL)
	{
		if (node->right != NULL)
			destroy(node->right);
		if (node->left != NULL)
			destroy(node->left);
		delete node;
		node = NULL;
	} // if
} // if

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
        length++;
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
            length++;
            return;
        } // if
        if (key < previous->key)
        {
            previous->left = inserted;
            length++;
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
        cout << "Item already in tree." << endl;
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

/*template<class T>
NodeType<T>* BinaryTree<T>::DeleteNode(NodeType<T> *root, T &key)
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
}*/


template<class T>
void BinaryTree<T>::deleteHelper(NodeType<T> *root, T &key)
{
/*	if(key<root->key)
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
	}*/
/*
	if (theNode == NULL)
		return theNode;
	if (key < theNode->key)
		theNode->left = deleteNode(theNode->left,key);
	else if (key > theNode->key)
		theNode->right = deleteNode(theNode->right,key);
	else
	{
		if (theNode->left == NULL && theNode->right == NULL)
			return NULL;
		else if (theNode->left == NULL)
		{
			NodeType<T> * temp = theNode->right;
			delete theNode;
			return temp;
		}
		else if (theNode->right == NULL)
		{
			NodeType<T> * temp = theNode->left;
			delete theNode;
			return temp;
		}
		NodeType<T> * temp = theNode->right;
		while (temp->left != NULL)
			temp = temp->left;
		theNode->key = temp->key;
		theNode->right = deleteTheNode(theNode->right, temp->key);
	} // if
	return theNode;*/
}


/*template<class T>
void BinaryTree<T>::deleteItem(T &key)
{
	//deleteHelper(root,key);
	NodeType<T> * exists = root;
	while (exists != NULL)
	{
		if (exists->key == key)
			break;
		else if (key > exists->key)
			exists = exists->right;
		else if (key < exists->key)
			exists = exists->left;
	} // if
	if (exists == NULL)
	{
		cout << "dne" << endl;
		return;
	} // if
//	bool retrievable = false;
	retrieve(key, retrievable);
	if (retrievable)
	{
		deleteHelper(root,key);
		return;
	} // if
//	cout << "dne" << endl;
	if (key == root->key)
	{
		NodeType<T> *temp = root;
		if (temp->right != NULL)
		{
			temp = temp->right;
		//	NodeType<T> *tempP = temp;
			while (temp->left != NULL)
			{
		//		if (temp->left->left == NULL)
		//			tempP = temp;
				temp = temp->left;
			} // while
			root->key = temp->key;
		//	tempP->left = NULL;
			delete temp;
			temp = NULL;
		}
		else
		{
			root = root-> left;
			delete temp;
			temp = NULL;
		} // if
		return;
	} // if
	NodeType<T> * tbd = root;
	NodeType<T> * tbdS = root;
	NodeType<T> * tbdP = root;
	while (tbd->key != key)
	{
		if (key > tbd->key)
			tbd = tbd->right;
		else if (key < tbd->key)
			tbd = tbd->left;
		if (tbd->right != NULL && tbd->right->key == key)
				tbdP = tbd;
		else if (tbd->left != NULL && tbd->left->key == key)
				tbdP = tbd;
	} // while
	if (tbd->right == NULL && tbd->right == NULL)
	{
		if (tbdP->right == tbd)
			tbdP->right = NULL;
		else if (tbdP->left == tbd)
			tbdP->left = NULL;
		delete tbd;
		tbd = NULL;
	}
	else if (tbd->right != NULL && tbd->left != NULL)
	{
		tbdS = tbd->right;
		while (tbdS->left != NULL)
			tbdS = tbdS->left;
		tbd->key = tbdS->key;
		delete tbdS;
		tbdS = NULL;
	}
	else
	{
		if (tbd->right == NULL)
		{
			if (tbdP->right == tbd)
				tbdP->right = tbd->left;
			else
				tbdP->left = tbd->left;
		}
		else
		{
			if (tbdP->right == tbd)
				tbdP->right = tbd->right;
			else
				tbdP->left = tbd->right;
		} // if
		delete tbd;
		tbd = nullptr;
	} // if
} // deleteItem */
template<class T>
void BinaryTree<T>::deleteItem(T &key)
{
	deleteTheNode(root, key);
} // deleteItem

template<class T>
NodeType<T> * BinaryTree<T>::deleteTheNode(NodeType<T> *theNode, T &key)
{
	if (theNode == NULL)
		return theNode;
	if (key < theNode->key)
		theNode->left = deleteTheNode(theNode->left,key);
	else if (key > theNode->key)
		theNode->right = deleteTheNode(theNode->right,key);
	else
	{
		if (theNode->left == NULL && theNode->right == NULL)
			return NULL;
		else if (theNode->left == NULL)
		{
			NodeType<T> * temp = theNode->right;
			delete theNode;
			theNode = NULL;
			return temp;
		}
		else if (theNode->right == NULL)
		{
			NodeType<T> * temp = theNode->left;
			delete theNode;
			theNode = NULL;
			return temp;
		}
		NodeType<T> * temp = theNode->right;
		while (temp->left != NULL)
			temp = temp->left;
		theNode->key = temp->key;
		theNode->right = deleteTheNode(theNode->right, temp->key);
	} // if
	return theNode;
} // deleteTheNode

/**
 * This method assumes the node exists and this isnt full comments
 */
template<class T>
NodeType<T> BinaryTree<T>::getP(NodeType<T> *current,T &item)
{
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

/*template<class T>
void subTreeAddtions(NodeType<T> *root,T &sumOfSubTrees)
{
  if( root == NULL )
   {
     return; 
   }// if
   if(root->left != NULL && root->right != NULL)
   {
     cout << "First "<< root->left->key +  root->right->key << endl;
     sumOfSubTrees = root->left->key + root->right->key;
   }
   else if (root->left == NULL && root->right != NULL) 
   {
     cout << "Second "<< root->left->key << endl;
     sumOfSubTrees = root->right->key;
   }
   else if (root->left != NULL && root->right == NULL)
   {
     cout << "Third "<< root->right->key << endl;
     sumOfSubTrees = root->left->key;
   }
   subTreeAddtions(root->left, sumOfSubTrees); 
   subTreeAddtions(root->right, sumOfSubTrees);
}*/

template<class T>
void BinaryTree<T>::getSumOfSubtreesHelper(NodeType<T> *root,T &item, bool &present )
{
   T sumOfSubTrees;
   if( root == NULL )
   {
     return; 
   }// if
   if( root->left != NULL && root->right != NULL && root->key == item )
   {
     sumOfSubTrees = root->left->key +  root->right->key;
     cout << "Sum of Subtrees: " << sumOfSubTrees << endl;
     present = true;
   }// if
   if(root->left == NULL && root->right != NULL && root->key == item )
   {
     sumOfSubTrees = root->right->key + sumOfSubTrees;
     cout << "Sum of Subtrees: " << sumOfSubTrees << endl;
     present = true;
   }// if
   if(root->left != NULL && root->right == NULL && root->key == item )
   {
     sumOfSubTrees = root->left->key+ sumOfSubTrees;
     cout << "Sum of Subtrees: " << sumOfSubTrees << endl;
     present = true;
   }// if
   if(root->left == NULL && root->right == NULL && root->key == item )
   {
     cout << "Sum of Subtrees: 0" << endl;
     present = true;
   }//if
   getSumOfSubtreesHelper(root->left, item, present); 
   getSumOfSubtreesHelper(root->right, item, present);
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
