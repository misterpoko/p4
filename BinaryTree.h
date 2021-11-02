#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
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
    int getNumLeafNodes();
    int getSumOfSubtrees();

	  NodeType<T> getP(NodeType<T> *current,T &key);
  
    //Helper methods
    void insertPt2(T &key, NodeType<T> *current, NodeType<T> *previous);
    void preOrderPrint(NodeType<T> *root) const;
    void inOrderPrint(NodeType<T> *root) const;
    void postOrderPrint(NodeType<T> *root) const;


  private:
    NodeType<T> *root;
    int length;
};

template<class T>
struct NodeType 
{
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
};

#endif
