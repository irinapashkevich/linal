#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Conteiner.h"
#include "node.h"

class list: public Container{
public:
    list();
    ~list();
    void insert(int a);
    void print();
    bool exists(int a);
    void remove(int a);
    void del();
    node* root;
    int data;
    bool b;
};

#endif // LIST_H_INCLUDED
