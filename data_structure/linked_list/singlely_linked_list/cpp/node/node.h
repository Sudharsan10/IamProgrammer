//
// Created by codezen on 6/12/21.
//

#ifndef CPP_NODE_H
#define CPP_NODE_H

namespace LL {
    /*
     * A Node class for defining a custom data structure for linked list
     */
    class Node {
    public:
        /* Constructors */
        /* ---> 01: Default  constructor <--- */
        Node() : Node{0, nullptr} {}

        /* ---> 02: Custom Constructors <--- */
        explicit Node(int data) : Node{data, nullptr}{}

        Node(int data, Node* next) : data_{data}, next_{next} {}

        /* Destructors */
        ~Node() {
            delete this->next_;
            this->next_ = nullptr;
        }

    private:
        int data_;
        Node *next_;

    };
}

#endif //CPP_NODE_H
