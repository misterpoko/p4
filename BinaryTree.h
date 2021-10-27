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

  private:
    NodeType<T> *root;
};

template<class T>
struct NodeType 
{
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
};

#endif
