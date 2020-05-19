#include <iostream>
#include "node.h"

using namespace std;

node::node()
{
    this->next=NULL;
    this->data=0;
    this->b=false;
};

node::~node()
{
}

node* node::del()
{
    node* l=this->next;
    delete[] this;
    while (l!=NULL)
    {
        node* p=l;
        l=l->next;
        delete p;
    }
    return l;
}

void node::insert(int a)
{
    if(this->b)
    {
        if (this->next==NULL)
            this->next=new node();
        this->next->insert(a);
    }
    else
    {
        this->data=a;
        this->b=true;
    }
};

void node::print()
{
    cout<<this->data<<" ";
    if (this->next!=NULL)
        this->next->print();
    else
        cout<<endl;
}

bool node::exists(int a)
{
    if (this->data==a)
        return true;
    if (this->next==NULL)
        return false;
    else
        return (this->next->exists(a));
}

node* node::remove(int a)
{
    if (this==NULL)
        return NULL;
    if (this->data==a)
    {
        node* l=this->next;
        delete[] this;
        return l;
    }
    this->next=this->next->remove(a);
    return this;
}
