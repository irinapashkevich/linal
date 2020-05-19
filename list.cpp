#include <iostream>
#include "list.h"
#include "Conteiner.h"
#include "node.h"

list::list()
{
    this->root=new node();
}

list::~list()
{
    this->root->del();
    delete[] this->root;
    this->root=0;
}

void list::insert(int a)
{
    this->root->insert(a);
}

void list::print(){
   this->root->print();
}

bool list::exists(int a){
     return this->root->exists(a);
}

void list::remove(int a){
     root=root->remove(a);
}
