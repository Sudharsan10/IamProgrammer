//
// Created by Sudo on 6/9/2021.
//

#ifndef CPP_SINGLYLINKEDLIST_H
#define CPP_SINGLYLINKEDLIST_H

#include "../node/node.h"

namespace LL{
    class SinglyLinkedList {

    public:
        /* Variables */
        std::shared_ptr<Node> root;

        /* Constructors */
        SinglyLinkedList():root{std::make_shared<Node>(0, nullptr)}{}

        /* Destructors */
        ~SinglyLinkedList() = default;

        /* Methods */
        void create_n_nodes(int n);
        [[maybe_unused]] void traverseAndPrint() const;
    };
}


#endif //CPP_SINGLYLINKEDLIST_H
