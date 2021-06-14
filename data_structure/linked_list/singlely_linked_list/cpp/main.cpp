#include <iostream>
#include "singlylinkedlist/singlylinkedlist.h"

int main() {
    LL::SinglyLinkedList head;
    head.create_n_nodes(5);
    head.traverseAndPrint();
    return 0;
}
