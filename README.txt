Orain Ferguson    811225938   onf32955&uga.edu
Nathaniel Mathers 811053553   nbm54197@uga.edu

Assignment 4

The program makes a tree and does metheds on the tree. It makes the list from the command line file.

Citations:
    Class PowerPoint sides
    (Delete) https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

How to compile
    make 
How to Run 
    main input.txt
    (Input file can be a line of strings, ints, or floats)

Files needed to run
    BinaryTree.cpp
    main.cpp
    Binary.h
    float-input.txt
    int-input.txt
    string-input.txt
    

Contributions
------------------------------------------------------
Orain Ferguson:

retrieve
preorder 
inorder
postorder
getlength
getNumSingleParents
getNumLeafNodes
getSumofSubtrees
main.cpp
general bugfixing

------------------------------------------------------
Nathaniel Mathers:

delete
insert
destructor
general bugfixing
memleaks

------------------------------------------------------
Complexity

Time Complexity
T(n) = 2T(n-1)-1
Big O Notation
O(n^2)

void getNumSingleParentHelper(NodeType<T> *root)
{
  if(root is NULL) // Base Case    O(1)
  {
    return;
  }
  else if ( (root left is not  NULL) AND (root right is NULL) OR (root left is NULL) AND (root right is not NULL))           O(1)
  {
    increase numberOfParents by 1;
  }
  getNumSingleParentHelper(root left);     O(n-1)
  getNumSingleParentHelper(root right);    O(n-1)
}

------------------------------------------------------

Time Complexity
T(n) = 2T(n-1)-1
Big O Notation
O(n^2)

void getNumLeafNodesHelper(root)
{
  if( root is NULL ) // Base Case   (1)
  {
    return;
  }
  else if( (root left is NULL) AND (root right is NULL) )  (1) 
  {
    increase numberOfLeafs by 1;
  } 
  getNumLeafNodesHelper(root left);        (n-1)
  getNumLeafNodesHelper(root right);       (n-1) 
} 

------------------------------------------------------

Time Complexity
T(n) = 4T(n-1)-1
Big O Notation
O(n^4)


T getSumOfSubtreesHelper(root,T &item )
{
   T sumOfSubTrees;
   if( root is NULL )  O(1)
   {
     return 0; 
   }
   return root key + getSumOfSubtreesHelper(root left, item) + getSumOfSubtreesHelper(root right, item);        O(n-1) + O(n-1) 
} //getSumOfSubtreesHelper


void getSumOfSubtrees(T &item)
{
  NodeType<T>* findValue = root;
	while (findValue is not NULL)  O(1)
	{
		if (item > findValue key)
			findValue = findValue right;
		else if (item < findValue key)
			findValue = findValue left;
		else if(findValue key is item)
			break;
	}
	if (findValue is not NULL)    O(1)
	{
		T var = getSumOfSubtreesHelper(findValue right, item) + getSumOfSubtreesHelper(findValue left, item);  O(n-1) + O(n-1) + O(1) 
		cout << "Sum of SubTrees: " << var << endl;
	} 
	else
  {
    cout << "Item no present or isnt a subtree" << endl; 
  } // if
} //getSumOfSubtrees

