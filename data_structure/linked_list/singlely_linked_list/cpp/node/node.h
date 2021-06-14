//
// Created by codezen on 6/12/21.
//

#ifndef CPP_NODE_H
#define CPP_NODE_H

#include<memory>
#include <utility>

namespace LL {
    /*
     * A Node class for defining a custom data structure for linked list
     */
    class Node {
    private:
        int data_;

    public:
        /* Variables */
        std::shared_ptr<Node> next_;

        /* Getters*/
        [[nodiscard]] int get_data() const {
            return data_;
        }

        /* Setters*/
        void set_data(int data) {
            this->data_ = data;
        }

        /* Constructors */
        /* ---> 01: Default  constructor <--- */
        Node() : Node{0, nullptr} {}

        /* ---> 02: Custom Constructors <--- */
        explicit Node(int data) : Node{data, nullptr} {}

        Node(int data, std::shared_ptr<Node> next) : data_{data}, next_{std::move(next)} {}

        /* Destructors */
        ~Node() = default;

    };
}
#endif //CPP_NODE_H
