#include <QtCore/QCoreApplication>
#include <bintree.h>
#include <iostream>
using namespace std;


int main()
{
    BinTree *m = new BinTree(9);
    m->insert(8);
    m->insert(7);
    m->insert(9);
    m->insert(10);
    cout<<m->has(10);
    m=m->remove(m,10);
    cout<<m->has(10);
    m->insert(10);
    cout<<m->has(10)<<endl;
    m->show();
    cout<<endl;
    BinTree::Iterator t = m->begin();
    do
    {
        cout<<t.next()<<endl;
    }while (t.hasNext());
}
