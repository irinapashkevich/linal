#include <iostream>
#include "Conteiner.h"
#include "list.h"
#include "node.h"

using namespace std;

int main()
{
    Container* c = new list();

    for(int i = 1; i < 30; i++)
        c->insert(i*i);

    cout << "Container after creation:" << endl;
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    c->remove(841);
    cout << "Container after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}
