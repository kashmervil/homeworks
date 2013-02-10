#ifndef BINTREE_H
#define BINTREE_H
#include <QStack>
#include <iostream>
using namespace std;
class BinTree
{
public:
    BinTree();
    BinTree(int a);
    ~BinTree();
    class Iterator;
    Iterator begin();
    void show();
    void insert(int a);
    BinTree* remove(BinTree *Tree, int a);
    bool has(int a);
    BinTree *findParent(BinTree *son);


private:
    int value;
    BinTree *leftNode;
    BinTree *rightNode;

};
class BinTree::Iterator
{
public:
    Iterator(BinTree *point)
    {
        cursor = point;
        stack.push(point);
    }
    int next();
    bool hasNext();

private:
    BinTree *cursor;
    QStack<BinTree*> stack;
};

#endif // BINTREE_H
