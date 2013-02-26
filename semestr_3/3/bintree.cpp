#include "bintree.h"

BinTree::BinTree()
{
    value = 0;
    leftNode = NULL;
    rightNode = NULL;
}
BinTree::BinTree(int a)
{
    value = a;
    leftNode = NULL;
    rightNode = NULL;
}
BinTree::~BinTree()
{
    delete leftNode;
    delete rightNode;
}
bool BinTree::has(int a)
{
    if (value == a)
        return true;
    else
        if(((value > a)&&(leftNode == NULL))||((value < a)&&(rightNode == NULL)))
            return false;
        else
            if(value > a)
                return leftNode->has(a);
            else
                return rightNode->has(a);
}
void BinTree:: insert(int a)
{
    if((!this->value)&&(!leftNode)&&(!rightNode))
        value = a;

    if(a < value)
    {
        if(!leftNode)
            leftNode = new BinTree(a);
        else
            leftNode->insert(a);
    }
    if(a > value)
    {
        if(!rightNode)
            rightNode = new BinTree(a);
        else
            rightNode->insert(a);
    }
}
BinTree* BinTree:: remove(BinTree *Tree, int a)
{

    BinTree* P, *v;
    if (!Tree)
        cout<<("tree is empty\n");
    else
        if (a < Tree->value)
            Tree->leftNode = remove(Tree->leftNode, a);
        else
            if (a > Tree-> value)
                Tree->rightNode = remove(Tree->rightNode, a);
    else
    {
        P = Tree;
        if (!Tree->rightNode)
            Tree = Tree->leftNode;
        else
            if (!Tree->leftNode)
                Tree = Tree->rightNode;
            else
            {
                v = Tree->leftNode;
                if (v->rightNode)
                {
                    while (v->rightNode->rightNode)
                    v = v->rightNode;
                    Tree->value = v->rightNode->value;
                    P = v->rightNode;
                    v->rightNode = v->rightNode->leftNode;
                }
                else
                {
                    Tree->value = v->value;
                    P = v;
                    Tree->leftNode = Tree->leftNode->leftNode;
                }
            }
        delete P;
    }
    return Tree;
}
void BinTree::show()
{
    if(this)
    {
        if(this->leftNode)
            this->leftNode->show();
        cout<<endl<<this->value;
        if(this->rightNode)
            this->rightNode->show();
    }
}
BinTree::Iterator BinTree::begin()
{
    return BinTree::Iterator(this);
}

bool BinTree::Iterator::hasNext()
{
    return !stack.isEmpty();
}

int BinTree::Iterator::next()
{
        cursor = stack.top();
        stack.pop();
        if(cursor->rightNode)
            stack.push(cursor->rightNode);
        if(cursor->leftNode)
            stack.push(cursor->leftNode);
        return cursor->value;
}

