#include <iostream>
#include "BinaryTree.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * This is the class constructor assigining appropriate values to an empty
 * binary search tree.
 */
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	length = 0;
  numberOfParents = 0;
  numberOfLeafs = 0; 
  first = true;
} // BinaryTree

/**
 * This is a class destructor which uses the destroy method to deallocate any dynamically used objects
 */
template<class T>
BinaryTree<T>::~BinaryTree()
{
	destroy(root);
	root = NULL;
} // ~BinaryTree

/**
 * This is a method meant to deconstruct the binary tree. It is recursive destroying all nodes from bottom to top right to left.
 * @param node is the root node or where it starts the destruction.
 */
template<class T>
void BinaryTree<T>::destroy(NodeType<T> *node)
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

/**
 * This is the actual insert method but it takes in different parameters.
 * @param key the item value being put into a tree.
 * @param current the node that is being used as a basepoint to insert somewhere
 * @param previous the node that is the parent of current.
 */ 
template<class T>
void BinaryTree<T>::insertPt2(T &key, NodeType<T> *current, NodeType<T> *previous)
{
	// inserting first object
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
	//inserting general objects
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
	// finding the node where it will be inserted and detecting if a duplicate
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
} // insertPt2

/**
 * This is the method that calls the real insert method.
 * It inserts an item into a binary Search Tree
 * @param key the value that we want to insert into the tree.
 */
template<class T>
void BinaryTree<T>::insert(T &key)
{
	insertPt2(key, root, NULL);
} // insert

/**
 * This is a method that calls the method to delete an item given that it exists.
 * @param key the value of a node to delete.
 */
template<class T>
void BinaryTree<T>::deleteItem(T &key)
{
	deleteTheNode(root, key);
	cout << "In-Order: ";
	inOrder();
	cout << endl << endl;
} // deleteItem

/**
 * This method deletes a node from the binary tree. If the node has two children it replaces itself with the
 * value of the node to the immediate right or its successor. Then you delete the successor node.
 * @param theNode cycles through nodes on the tree until it finds the one to delete
 * @param key the value of the node that you want to delete
 * @return NodeType<T>* used to recursively find the node to delete.
 */
template<class T>
NodeType<T> * BinaryTree<T>::deleteTheNode(NodeType<T> *theNode, T &key)
{
	//base case of not existing
	if (theNode == NULL)
	{
		cout << "Item not in tree" << endl;
		return theNode;
	} // if
	// find the node to actually delete
	if (key < theNode->key)
		theNode->left = deleteTheNode(theNode->left,key);
	else if (key > theNode->key)
		theNode->right = deleteTheNode(theNode->right,key);
	else
	{
		//deleting the node
		//this is deletion of a leaf
		if (theNode->left == NULL && theNode->right == NULL)
		{
			length--;
			return NULL;
		} // if
		//this is deletion of only having one child 
		else if (theNode->left == NULL)
		{
			NodeType<T> * temp = theNode->right;
			delete theNode;
			theNode = NULL;
			length--;
			return temp;
		}
		else if (theNode->right == NULL)
		{
			NodeType<T> * temp = theNode->left;
			delete theNode;
			theNode = NULL;
			length--;
			return temp;
		}
		//deletion of having two children by finding immediate right
		//taking its value then deleting immediate right node.
		NodeType<T> * temp = theNode->right;
		while (temp->left != NULL)
		temp = temp->left;
		theNode->key = temp->key;
		theNode->right = deleteTheNode(theNode->right, temp->key);
	} // if
	return theNode;
} // deleteTheNode

/**
 * This is the actual retrieve function but takes in different parameters
 * @param root recursive way of finding the node existance
 * @param item item's value trying to be found
 * @param found how to check if the item has been found
 */
template<class T>
void retrieveHelper(NodeType<T> *root, T &item, bool &found)
{
	// case doesnt exist
   if( root == NULL )
   {
     return; 
   }// if
	// case does exists
   else if( root->key == item )
   {
     found = true;
     return;
   }// else if
	//recursively find if exists
   retrieveHelper(root->left,item, found); 
   retrieveHelper(root->right,item, found);
}
 
/**
 * This is the retrieve method which takes in a boolean and sees if an item exists
 * in the binary search tree.
 * @param item wanting to be found
 * @param found whether or not it has been found
 */
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
  retrieveHelper(root, item, found);
}// retrieve

/**
 * Recursive way of printing Binary search tree in a preorder fashion.
 * @param root where it starts the preOrderPrint.
 */
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

/**
 * This is the caller of preOrderPrint which takes in no parameters to call the function.
 */
template<class T>
void BinaryTree<T>::preOrder() const
{
	preOrderPrint(root);
} // preOrder

/**
 * Recursive way of printing Binary search tree in a inorder fashion.
 * @param root where it starts the inOrderPrint.
 */
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

/**
 * This is the caller of inOrderPrint which takes in no parameters to call the function.
 */
template<class T>
void BinaryTree<T>::inOrder() const
{
	inOrderPrint(root);
} // inOrder

/**
 * Recursive way of printing Binary search tree in a postorder fashion.
 * @param root where it starts the postOrderPrint.
 */
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

/**
 * This is the caller of PostOrderPrint which takes in no parameters to call the function.
 */
template<class T>
void BinaryTree<T>::postOrder() const
{
	postOrderPrint(root);
} // postOrder

/**
 * This returns the length of the binary search tree or the amount of nodes in it.
 */
template<class T>
int BinaryTree<T>::getLength() const
{
  return length;
} //getLength

/**
 * This method calls the getNumSingleParentHelper and displays the number of single parents
 * it discards the value after in case the amount has changed.
 */
template<class T>
void BinaryTree<T>::getNumSingleParent()
{
  getNumSingleParentHelper(root);
  cout << "Number of single parents: " << numberOfParents << endl;
  numberOfParents = 0;
} //getNumSingleParent

/**
 * This is a recursive method that gets the number of single parents in the tree.
 * @param root the place it starts from a recursive standpoint.
 */
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

/**
 * This gets the number of leafs in the tree recursively.
 * @param root the place where it starts from a recursive standpoint.
 */
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

/**
 * This is the method that calls getNumLeafNodesHelper to count the number of leaf nodes.
 * It resets its count after calling the method in case the tree changes.
 */
template<class T>
void BinaryTree<T>::getNumLeafNodes()
{
  getNumLeafNodesHelper(root);
  cout << "Number of leaf nodes: " << numberOfLeafs << endl;
  numberOfLeafs = 0;
} //getNumLeafNodes

/**
 * This is a method that gets the sum of subtrees.
 * @param root where it starts from a recursive standpoint
 * @param item the item it needs to find where to start the recursion
 */
template<class T>
T BinaryTree<T>::getSumOfSubtreesHelper(NodeType<T> *root,T &item )
{
   T sumOfSubTrees;
   if( root == NULL )
   {
     return 0; 
   }
   return root->key + getSumOfSubtreesHelper(root->left, item) + getSumOfSubtreesHelper(root->right, item);
} //getSumOfSubtreesHelper

/**
 * This method callse the getSumofsubtreeshelper. It initializes the data needed for it and detects a no subtree case
 */
template<class T>
void BinaryTree<T>::getSumOfSubtrees(T &item)
{
  NodeType<T>* findValue = root;
	while (findValue != NULL)
	{
		if (item > findValue->key)
			findValue = findValue->right;
		else if (item < findValue->key)
			findValue = findValue->left;
		else if(findValue->key == item)
			break;

	} // while
	if (findValue != NULL)
	{
		T var = getSumOfSubtreesHelper(findValue->right, item) + getSumOfSubtreesHelper(findValue->left, item);
		cout << "Sum of SubTrees: " << var << endl;
	} 
	else
  {
    cout << "Item not in tree" << endl; 
  } // if
} //getSumOfSubtrees

//Needs to stay at the bottom
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
