#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

template<class T> struct NodeType;
template<class T>
class BinaryTree 
{
  public:
    BinaryTree();
    ~BinaryTree();
    void insert(T &key);
    void deleteItem(T &key);
    void retrieve(T &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength() const;
    
    
    
    void getNumSingleParent();
    void getNumSingleParentHelper(NodeType<T> *root);
  
    void getNumLeafNodes();
    void getNumLeafNodesHelper(NodeType<T> *root);
    
    void getSumOfSubtrees(T &item);
    T getSumOfSubtreesHelper(NodeType<T> *root,T &item);

	  NodeType<T> getP(NodeType<T> *current,T &key);
  
    //Helper methods
    void insertPt2(T &key, NodeType<T> *current, NodeType<T> *previous);
    void preOrderPrint(NodeType<T> *root) const;
    void inOrderPrint(NodeType<T> *root) const;
    void postOrderPrint(NodeType<T> *root) const;



    // Delete Helpers
    void DeleteNode(NodeType<T> *root, T &key);
    void getPredecessor(NodeType<T> *root, T &data);
	  void destroy(NodeType<T> *node);
	  NodeType<T> * deleteTheNode(NodeType<T> * theNode, T &key);

  private:
    NodeType<T> *root;
    int length;
    int numberOfParents; 
    int numberOfLeafs;
    bool first;
};

template<class T>
struct NodeType 
{
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
};

#endif
